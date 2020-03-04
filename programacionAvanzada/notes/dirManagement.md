Directory management
===
### Functions
* getcwd()
  * get current work directory
* opendir(directory)
  * returns null if it couldnt open the file
    * directory doesnt exit
    * permissions
    * not a directory
* readdir(directory)
  * goes through all the pointers (NOT FILES) of the files
  * file '.' is the current directory
  * file '..' is the previous directory
  * the file are not ordered. They are how they were inserted
* stat(filename, &info)
  * receives information of the file and saves it into info
  * variables:
    * _st_mode_ -> to check thing like file type
      * S_ISDIR(info.st_mode)
* lstat()
  * respects the links
    * stat gives the information of the file that the link is pointing to

### Variables
* _PATH_MAX_
  * Defined by the operating system
  * Always use _PATH_MAX_+1

### Variable type
* _DIR_
* _struct dirent_
  * found inside the directory
  * pointers to files
<pre><code>struct dirent{
  ino_t d_ino;                /* Inode number */
  off_t d_off;                /* Not an offset; see below */
  unsigned short d_reclen;    /* Length of this record */
  unsigned char  d_type;      /* Type of file; not supported by all filesystem types */
  char  d_name[256];          /* Null-terminated filename */
}</code></pre>
* _struct stat_
  * information about a file
<pre><code>struct stat{
  dev_t st_dev;             /* ID of device containing file */
  ino_t st_ino;             /* Inode number */
  mode_t st_mode;           /* File type and mode */
  nlink_t st_nlink;         /* Number of hard links */
  uid_t st_uid;             /* User ID of owner */
  gid_t st_gid;             /* Group ID of owner */
  dev_t st_rdev;            /* Device ID (if special file) */
  off_t st_size;            /* Total size, in bytes */
  blksize_t st_blksize;     /* Block size for filesystem I/O */
  blkcnt_t st_blocks;       /* Number of 512B blocks allocated */

  /* Since Linux 2.6, the kernel supports nanosecond
     precision for the following timestamp fields.
     For the details before Linux 2.6, see NOTES. */

  struct timespec st_atim;  /* Time of last access */
  struct timespec st_mtim;  /* Time of last modification */
  struct timespec st_ctim;  /* Time of last status change */

  #define st_atime st_atim.tv_sec   /* Backward compatibility */
  #define st_mtime st_mtim.tv_sec
  #define st_ctime st_ctim.tv_sec
}</code></pre>

### To check a file type
https://www.gnu.org/software/libc/manual/html_node/Testing-File-Type.html
