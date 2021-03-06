Signals
====
> Signals are software interrupts. (...) Signals provide a way of handling asynchronous events -for example, a user at a terminal typing the interrupt key to stop a program or the next program in a pipeline terminating prematurely.

### Header: <signal.h>

## Signal Concepts
* Every signal has a name
    * All begin with the three characters **SIG**.
    * Defined by positive integer constant
    * Signal 0 = kill
* Conditions that can generate a signal
    1. The _terminal-generated signals_ occur when **users** press certain terminal keys.
    2. **Hardware exceptions** generate signals
    3. The `kill(2)` function allows a process to send any signal to **another process** or **procces group**.
    4. The `kill(1)` command allows us to send signals to other processes. Often used to terminate a **runaway background process**.
    5. **Software conditions** can generate signals when a process could be notified of various events.

* We can tell the kernel to do one of three things when a signal occurs. We call this the __disposition__ of the signal, or the __action__ associated with a signal.
    1. **Ignore** the signal.
        * 2 signals can never be ignored: **SIGKILL** and **SIGSTOP**
    2. **Catch** the signal.
        * To do this we tell the kernel to call a function of ours whenever the signal occurss. In our function we can do whatever we want to handle the condition.
    3. Let the **default** action apply.

## Signal Description Table
When the **default action** is labeled _terminate+core_, it means that a memory image of the process is left in the file named _core_ of the current working directory of the process. This file can be used with most UNIX System debuggers to examine the state of the process at the time it terminated. The core file will not be generated if:
1. The process was set-user-ID and the **current user is not the owner of the program file**.
2. The process was set-group-ID and the **current user is not the group owner of the file**.
3. The **user does not have permission to write in the current workind directory**
4. The file already exists and the **user does not have permition to write to it**.
5. The **file is to big**.


Name     | Description                                             | Default Action
---------|---------------------------------------------------------|---------------
SIGABRT  | Abort anormal termination (abort)                       | terminate + core
SIGALRM  | This signal is generated when a timer set with the `alarm`function expires. Also generated when an interval timer set by the `setitimer(2)`function expires.| terminate       
SIGBUS   | The signal indicates an implementation-defined hardware fault. Usually on certain types of memoery faults | terminate + core
SIGCANCEL| Threads library internal use. Note meant for general use| ignore          
SIGCHLD  | Whenever a process terminates or stops, the SIGCHLD signal is sent to the parent. By default, this signal is ignored, so the parent must catch the signal if it wants to be notified whenever a child's status changes.| ignore          
SIGCONT  | Continue stopped process                                | continue/ignore 
SIGEMT   | Hardware fault                                          | terminate + core
SIGFPE   | Arithmetic exception                                    | terminate + core
SIGFREEZE| Checkpoint freeze. Notify processes that need to take special action before freeezing the system stat. | ignore          
SIGHUP   | Hangup. Sent to the controlling process associated with a controlling terminal if a disconnect is detected by the terminal interface. This signal is commonly used to notify daemon processes to reread their configuration files. The reason **SIGHUP** is chosen for this task is that a daemon should not have a controlling terminal and would normally never receive this signal. | terminate
SIGILL   | Illegal hardware instruction.                           | terminate + core
SIGINFO  | Thid BSD signal is generated by the terminal driver when we type the status key (often Control-T) The signal is sent to all processes in the foreground. Normally causes status information on processes in the foregrounf process group to be displayed on the terminal| ignore          
SIGINT   | Terminal interrupt character. Often DELETE or Control-C | terminate
SIGIO    | Asynchronous I/O                                        | terminate/ignore
SIGIOT   | Hardware fault                                          | terminate/ignore
SIGJVM1  | Java virtual machine internal use                       | ignore          
SIGJVM2  | Java virtual machine internal use                       | ignore          
SIGKILL  | Termination                                             | terminate       
SIGLOST  | Resource lost                                           | terminate       
SIGLWP   | Threads library internal use. Not available for general use| terminate/ignore
SIGPIPE  | Write to pipe with no readers                           | terminate       
SIGPWR   | Power fail/restart                                      | terminate/ignore
SIGQUIT  | Generated by the terminal driver when we press the terminal quit key (often Control-backslash). This signal is sent to all processes in the foreground process group, terminates them and generates a _core_ file.| terminate + core
SIGSEGV  | Invalid memory reference                                | terminate + core
SIGSTOP  | Stop                                                    | stop process
SIGSYS   | Invalid system call                                     | terminate + core
SIGTERM  | Sent by the `kill(1)` command by default. Because it can be caught by applications, it gives them a chance to terminate gracefully by cleaning up before exiting.| terminate          
SIGTHAW  | Checkpoint thaw. Used to notify processes that need to take special action when the system resumes operation after being suspended| ignore
SIGSTP   | Interactive stop signal that is generated by the terminal driver when we press the terminal suspend key (often Control-Z).| terminate
SIGUSR1  | User-defined signal                                     | terminate
SIGURG   | Urgent condition                                        | ignore
SIGWINCH | Terminal window size change                             | ignore
SIGXCPU  | CPU limit exceeded (setrlimit)                          | terminate + core
SIGXFSZ  | File size limit exceeded (setrlimit)                    | terminate + core
SIGXRES  | Resource control exceeded                               | ignore

## Functions

### _signal_ 
```c
#include <signal.h>
void (*signal(int signo, void (*func)(int)))(int);
```
* `signo` argument is just the name of the signal
* The value of `func` is:
    1. The constant **SIG_IGN**
    2. The constant **SIG_DFL**
    3. The address of a system function to be called when the signal occurss. If we specify **SIG_IGN**, we are telling the system to ignore the signal.
* `signo` argument is just the name of the signal
* The value of `func` is:
    1. The constant **SIG_IGN**. If specified we are telling the system to ignore the signal.
    2. The constant **SIG_DFL**. if specified we are setting the action associated with the signal to its default value.
    3. The address of a system function to be called when the signal occurss. This function is also called _signal handler_ or _signal catching function_.

#### Example
> Page 324

```c
#include "apue.h"
static void sig_usr(int);
int main (void){
  if (signal(SIGUSR1, sig_usr) == SIG_ERR)
    err_sys("Cant catch SIGUSR1");
  if (signal(SIGUSR2, sig_usr) == SIG_ERR)
    err_sys("Cant catch SIGUSR2");
  for ( ; ; )
    pause();
}

static void sig_usr (int signo){
  if (signo == SIGUSR1)
    printf("Received SIGUSR1\n");
  else if (signo == SIGUSR2)
    printf("Received SIGUSR2\n");
  else
    err_dump("Received signal %d\n", signo);
}
```
