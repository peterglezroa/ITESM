Files
===
### Libs
1. &lt;unistd.h&gt;
2. &lt;sys/types.h&gt;
3. &lt;sys/stat.h&gt;
4. &lt;fcntl.h&gt;

### File Descriptors
* All files are referred to by file descriptors.
* They are non-negative number
* UNIX associates:

file descriptor | associated
----------------|----------------------------
0               | standard input of a process
1               | standard output
2               | standard error

### Functions

#### open
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fctnl.h>

int open(const char *pathname, int oflag, .. / *, mode_t mode * / );
```
**Returns file descriptor if ok, -1 on error**
* _oflag_
  oflag    |description                             |optional
  ---------|----------------------------------------|-------------
  O_RDONLY  |Open for reading only.                                                     |no
  O_WRONLY  |Open for writing only.                                                     |no
  O_RDWR    |Open for reading and writing.                                              |no
  O_APPEND  |Append to the end of file on each write.                                   |yes
  O_CREAT   |Create the file if it doesn't exit. Requires a third argument to on the open function, _mode_, which specifies the access permission bits of the new file.|yes
  O_EXCL    |Generate an error if O_CREAT is also specified and the file already exists |yes
  O_TRUNC   |If the file exists, is successfully opened truncate its length to 0        |yes
  O_NOCTT   |If the pathname refers to a terminal device, do yest allocate the device as the controlling terminal for this process. |yes
  O_NONBLOCK|If the _pathname_ refers to a **FIFO**,a block special file, or character special file, this option sets the yesnblocking mode for both the opening of the file and for subsequent I/O|yes
  O_SYNC    |Have each _write_ wait for physical I/O to complete                        |yes
  **There can only be one not optional**
  
* if _NAME_MAX_ is 14 and we try to create a new file with 15 characters:
  * constant _POSIX_NO_TRUNC_ determines whether long filenames are truncated or an error is returned.

#### creat
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int creat(const char *pathname, mode_t mode);
// this is equal to open(pathname, O_WRONGLY, O_CREAT, O_TRUNC, mode);
```
**Returns file descriptor if ok, -1 on error**
* Cannot read file after opened. Its better to use **_open_** function

#### close
```c
#include <unistd.h>

int close(int filedescriptor);
```

#### lseek
```c
#include <sys/types.h>
#include <unistd.h>

off_t lseek(int filedescriptor, off_t offset, int whence);
```
* _current file offset_ -> positive int that measures the number of bytes from the beginning of the file.
* _whence_:
  whence  | type
  --------|---------------------------------------------------
  SEEK_SET|offset is set to _offset_ bytes from the beginning.
  SEEK_CUR|offset is set to its current value plus the offset (can be negative)
  SEEK_END|offset is set to the size of the file plus the offset (can be negative)

#### read
```c
#include <unistd.h>

ssize_t read(int filedescriptor, void *buff, size_t nbytes);
```
**Returns number of bytes read,0 if end of file, -1 on error**
* Cases in which the number of bytes actually read is less than the amount expected:
  * If end of file is reached
  * When reading from a terminal device, normally up to one line is read at a time.
  * When reading from a network, buffering within the network may cause less than the requested amount to be returned.
* unsigned char for 2 bits
* unsigned int for 16 bits

#### write
```c
#include <unistd.h>

ssize_t write(int filedescriptor, const void *buff, size_t numberbytes);
```
**Returns number of bytes written if ok, -1 on error**
<center style="color:red;font-size:2rem">¡Note: use only the read and write functions for more efficiency!</center>

#### dup
```c
#include <unistd.h>

int dup(int filedes);
```
**Return new file descriptor if OK, -1 on error**

* Duplicates a file descriptor
* The returned file descriptor is guaranteed to be the lowest numbered available.

#### dup2
```c
#include <unistd.h>

int dup2(int filedes, int filedes2);
```
**Return new file descriptor if OK, -1 on error**

* Duplicates a file descriptor
* We specify the value of the new descriptor with the _filedes2_.
  * If _filedes2_ is already open, it is first closed.
  * If _filedes_ equals _filedes_, then returns _filedes2_ without closing it.

#### fcntl
```c
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int fcntl(int filedes, int cmd, ... /* int arg */ );
```
**Return depens on _cmd_ if OK, -1 on error**

* It can change the properties of a file that is already open.

cmd     | description
--------|------------
F_DUPFD |Duplicate the file descriptor _fieldes_.The new file descriptor is returned as the value of the function. The new descriptor shares the same file table entry as _filedes_, but the new descriptor has its own set of file descriptor flags and its _FD_CLOEXEC_ file descriptor is cleared.
F_GETFD |Return the file descriptor flags for the _filedes_ as the value of the function.
F_SETFD |Set the file descriptor flags for _filedes_. The new flag value is set from the third argument (taken as an integer).
F_GETFL |Return the file status flags for _filedes_ as the value of the function. **(open function flags)**. The three access flags (O_RDONLY, O_WRONLY, O_RDWR) are not separate bits that can be tested. Therefore we must first use the _O_ACCMODE_ mask to obtain the access mode bits and then compare the result against any of the three values.
F_SETFL |Set the file status flags to the value of the third argument.
F_GETOWN|Get the process ID or process group ID currently receiving the _SIGIO_ and _SIGURG_ signals.
F_SETOWN|Se the process ID or process group ID to receive the _SIGIO_ and _SIGURG_ signals. A positive _arg_ specifies a process ID. A negative _arg_ implies a process group ID equal to the absolute value of _arg_.


### File sharing
![file sharing][filestruct]
> \1. Every process has an entry in the process table. Within each process table entry is a table of open file descriptors, which we can think of as a vector with one entry per descriptor. Associated with each file descriptor are:  
  \- the file descriptor flags  
  \- a pointer to a file entry.  
\2. The kernel mantains a file table for all open files. Each file table entry contains:  
  \- the file status flag of the file (read, write, append, etc)  
  \- the current file offset  
  \- a pointer to the v-node table entry for the file.  
\3. Each open file (or device) has a v-node structure. The v-node contains information about the type of file and pointers to functions that operate on the file. For most files the v-node also contains the i-node. This information is read from disk when the file is opened, so that all the pertinent information about the file is readily available. (...)  
**Richard, S. W. (1992). Advanced programming in the UNIX environment. Page 57**

### Exam questions
En un proceso recién aplicado. Si yo abro un archivo ¿Cuál es el valor numérico del file que me va regresa? 3. Porque ya tienen 3 files descriptors.

En un programa nuevo. Si hago:
```c
char* s[] = "Hola Mundo";
fd = open(__,O_WRLONY__);
close(1); // Se cierra la salida estándar (stdout) y libero el file escrito
dup(fd); // Me regresa un file escrito en el mismo recurso. Osea dos files en el mismo recurso
close(fd); // 
write(fd, s, sizeof(s));
```
¿Dónde imprime? Se imprime en la pantalla y en el archivo.


[filestruct]: ../img/filesharing.jpeg
