--------------------- Minitalk and foundation of Process-management  ------------------------

What is Inter-Process-Communication(ipc) ?

    (IPC) is a mecanisum that allow communication of one process with anouther process 
    1 - Related processes , it usaly a process that relate to his parent .(e.g Pipe)
    2 - Not related so they are usally different processes each one acommplish different (e.g FIFO)
        taskes and they communicated with each other.
    3 - Signals : it way you can communicate with many processes using signal
    4 - shared Memory : also a way for comunication betwwen processes 
    i like to 

What is a Signals ?

    Signal is a from of Inter Process Comuniction exist to notify a process that a specific event
    has occurred so in simple term a signal is an asynchronous , so it interrupt a process 
    at any point, forcing it to pause the current activity and handle the signal.
    each signal has unique number that differentiates it from the other signals and an associated
    a default action that determines the behavoir when the process receive that signal
        SIGHUP : terminal line hangup
        SIGINT : interrupt program (ctrl + c)
        SIGQUIT: quit program (ctrl + d)
        SIGKILL: kill the program
        SIGBUS : buss error
        SIGSTOP: it stop the program
        SIGCONT: it continue after stoping

what is a process-Group ? 

    well a process-group is a collection of processes that can be manged in signal entity, and one
    thing more important about the process group is that the first process or (lower PID number)
    and his caracterise by number or an index called PGID,
    
Why we need a process group ?

    for orginise and manage multiple processes and it help for distrubution of signals to multiple
    processes at once . example the kill/ctrl+c/ctrl+z command it send to a signal to all processes
    in the group so it useful for controlling processes. in the shell we also use group to manage 
    the job example the pipline (comand-1 | command-2) and so on and so on ...

What is orphan-process ?

    is a child-process that remain running evan after it parent process terminated or completed
    and that orphan-will controlled by init-process

What is Daemon Process?

    every process run in the backgound of couputer and it terminate only when the systeme is shutdown
    they handle tasks like system maintenace, network service or hardwar management

What is a zombie Process ?

    a process that terminated they execution but still has an entry to his process table becouse
    his parent it not yet read it exit status, and he consuming the minimum resources(cpu, memory)

what is a page table (process control block) ?

    it a table that conatine entry for each process and it store inforamation about the process
        . Process ID (PID) an unique identifier to each process
        . Parent Process ID (PPID) : is a process id of the process parent
        . process Group ID (PGID)
    and also contain the status of each process Sleepling ,Waiting ,Zombie etc..
    and the most important the cpu state such as register, program counter and stack pointer
    and inforamtion about memory management (page-table),file descriptors 
    and Miscellaneous all information about directory enviroment variable
    yes and it so important becouse it help for process management scheduling resourse allocation 
    even the interprocess communication like signal and pipe and shared memory

What is Pipes ?

    pipes are simple synchronized way of passing information between two processes , i view it like
    simple file that store amount of data an he use FIFO schema to retrieve data so the data written
    ane read from another pipe allow data to flow unidirectionally between two process 
    it used for chain the command and enable the process to work to gether in a producer and consumer
    model and pipes work by creating a buffer in memory that act s as a conduit for transfering data
    between process and this buffer is temporary and in additional two processes unrelated they
    communicate via a file like interface if they related they used fork()

What is the diff between pipe and socket ?

    the other important differentce is that we can use pipes to connect processes on the same 
    physical machine .but in the other hand we ,use socket to establish connection between processes
    on different physical machine.

what is a signalemptyset ?
    
    it initialise a signal set given by the set to empty, and it return 1 if the signum is number
    of set , 0 if the signal signum not a member of set and -1 in the case of the error
    so it creat a signal that cheack it work an clean and in a empty state for preventing udefined
    behavor or a garbege value 
What is Kill() ?

    used to send any signal to any process group or process.
        . if pid is positive then signal sig is sent to pid
        . if pid is equal to 0, then sig is sent to every process in the process group of
            the !! current !! process
        . if pid is equal to -1 the signal is send to every process which the calling process has the
            permission to send signals, except for the init process
        . if pid is less than -1 then it send to every process in the group process
        . if the signal is 0 mean that no sig is sent, but the error cheack is performed .
            it can be use to cheak whether the calling process has the permission to signal
            a specific process.

What is sigaction ?

    int sigaction(int signum, const struct sigaction *Nullable restrict act, struct sigaction *
        _Nullable restrict oldact);
    a sigaction is syatem call is used to change the action taken by a process on receipt of a
    specific signal we can use any signum exacpt the SIGKILL and SIGSTOP
    in additional th sigactio can be define as this structer below :

        struct sigaction {
            void (*sa_handler)(int); // TRADITIONAL HANDLER FOR SIGNALS
            void (*sa_sigaction)(int, siginfo_t *, void); // HANDLER WITH ADDITIONAL INFO (sa_info)
            sigset_t sa mask; // SET THE SIGNAL TO BE BLOCK DURING THE HANDLER
            int sa_flags; // FLAGS TO MODIFY FOR HANDLING THE BEHAVOR
            void (*sa_restorer)(void); // USED FOR THE OLD IMPLEMENTATIONS, TYPCALLY UNUSED
        };
    so it allow you to specify detailed behavoir for a signal compared to the older signal() 
    and give you more context about the signal 

what is sigaddset ?

    is a function in POSIX standard used to add a signal to signal set(collection of signals)
    and it used to speciafy wich signal a process want to block 

what is the diff between sigaction and signal ?

what is thread ?

signal and traps ?

some inforamation about (Process Mangement)

