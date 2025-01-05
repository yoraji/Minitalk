##### minitalk ####

    signal : simply it is a interruption that notifies a process about an event ,often prompting it to
pause and handle the occurence before resuming
and it can be used to inform a process of various events such as suspension ,sigfault, system call
kill/raise. the signals is very important to avoid a race condition or deadlocks
Understanding some system call
    
    signal(): Set a simple simple signal handler.
    sigation(): Advenced, thread-safe way to handle signals.
    kill(): it will send a signal to a process
    raise(): it send a signal to the current process
    pause(): it wait for a signal 
    sigpending():cheack pending signal (!it not allowed in the project)

or Termination of child process  ,if you anticipte an event that cause signal , you need define a handler for that signal. 

what is an handler of signal ? what is the purpose of implementent in this project ??
    
    a signal handler id function define in the program to handle a specific signal.
    so when the signal is delivered to process, the handler is excuted to respond to the event
    so you can concueer that it used to take a custom action when the signal is recevied  
what is SIGUSR1 and SIGUSR2 ? why we need those ?
    
    we need it to transmit BINARY data (bit of the message ) between the server and client
    and for not having any conflicting between signals (bit by bit communication protocol) and often
    the client send (SIGUSR1 or SIGUSR2) to server process using kill() function
why you need to use valotile sig_atomic_t in you project
    
    for prevent the confilct between the signals if we dont user it you will write some garbege number
    in addition it guarantees atomicity, ensuring that the variable can be read or written in a
    single operation, preventing data races.
    volatile : ensures the compiler doesn't optimize it and always reads its latest value.

understanding the standard signals:
    SIGINT  :(2) sent when the user press (Ctrl+c)
    SIGTERM :(15) Sent to terminate a process gracefully
    SIGHUB  :(1) it send when a terminal is closed 
    SIGKILL :(9) Immediately terminate a process (and it can not be ignored or caught).
    SIGSEGV :(11) indicate an invalid memory access (Sigfaul) 
    
what is signal mask and blocking with sigpromask ?
    A signal mask is mechanisum to control whil signal a process can block temporarily. Blocking
    a signal prevent it from being  delivered to the process until it's unblocked. the purpose of it 
    Ensures that signal handlers don’t interfere with sensitive operations by delaying their 
    execution until unblocked
