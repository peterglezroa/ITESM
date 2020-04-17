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

## Singal Description Table
When the **default action** is labeled _terminate+core_, it means that a memory image of the process is left in the file named _core_ of the current working directory of the process. This file can be used with most UNIX System debuggers to examine the state of the process at the time it terminated. The core file will not be generated if:
1. The process was set-user-ID and the **current user is not the owner of the program file**.
2. The process was set-group-ID and the **current user is not the group owner of the file**.
3. The **user does not have permission to write in the current workind directory**
4. The file already exists and the **user does not have permition to write to it**.
5. The **file is to big**.


Name     | Description                                            | Default Action
---------|--------------------------------------------------------|---------------
SIGABRT  |Abort anormal termination (abort)                       | terminate + core
SIGALRM  |This signal is generated when a timer set with the `alarm`function expires. Also generated when an interval timer set by the `setitimer(2)`function expires.| terminate       
SIGBUS   |Hardware fault                                          | terminate + core
SIGCANCEL|Threads library internal use                            | ignore          
SIGCHLD  |Change in status of child                               | ignore          
SIGCONT  |Continue stopped process                                | continue/ignore 
SIGEMT   |Hardware fault                                          | terminate + core
SIGFPE   |Arithmetic exception                                    | terminate + core
SIGFREEZE|Checkpoint freeze                                       | ignore          
SIGHUP   |Hangup                                                  | terminate       
SIGILL   |Illegal instruction                                     | terminate + core
SIGINFO  |Status request from keyboard                            | ignore          
SIGINT   |Terminal interrupt character                            | terminate       
SIGIO    |Asynchronous I/O                                        | terminate/ignore
SIGIOT   |Hardware fault                                          | terminate/ignore
SIGJVM1  |Java virtual machine internal use                       | ignore          
SIGJVM2  |Java virtual machine internal use                       | ignore          
SIGKILL  |Termination                                             | terminate       
SIGLOST  |Resource lost                                           | terminate       
SIGLWP   |Threads library internal use                            | terminate/ignore
SIGPIPE  |Write to pipe with no readers                           | terminate       
SIGPOLL  |Pollable event (poll)                                   | terminate       
SIGPROF  |Profiling time alarm (setitimer)                        | terminate       
SIGPWR   |Power fail/restart                                      | terminate/ignore
SIGQUIT  |Terminal quit character                                 | terminate + core
SIGSEGV  |Invalid memory reference                                | terminate + core
SIGSTOP  |Stop                                                    | stop process
SIGSYS   |Invalid system call                                     | terminate + core
SIGTERM  |Termination                                             | terminate          
SIGTHAW  |Checkpoint thaw                                         | ignore
SIGUSR1  |User-defined signal                                     | terminate
SIGURG   |Urgent condition                                        | ignore
SIGWINCH |Terminal window size change                             | ignore
SIGXCPU  |CPU limit exceeded (setrlimit)                          | terminate + core
SIGXFSZ  |File size limit exceeded (setrlimit)                    | terminate + core
SIGXRES  |Resource control exceeded                               | ignore

