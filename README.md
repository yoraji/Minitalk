---------------------------------- minitalk -------------------------------------------------

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
    has occurred so in simple term a signal is an asynchronous , so it can interorupt a process 
    at any point, forcing it to pause the current activity and hndle the signal.
what is aprocess-Group ? 

well a process-group is a collection of processes that can be manged in signal entity, and one thing more important about the process group is that the first process or (lower PID number)
and his caracterise by number or an index called PGID,
`:

what is a signalemptyset ?

    type of signal set to an empty state ,ensuring that no signal are included in the set
    int sigemptyset(sigset_t *set);
    it clean all signal from set and making it set to empty
what is sigaddset ?
    is a function in POSIX standard used to add a signal to signal set(collection of signals)
    and it used to speciafy wich signal a process want to block 
what is a signal ?
what is the diff between sigaction and signal ?
what is thread ?
signal and traps ?

some inforamation about (Process Mangement)

# Minitalk
