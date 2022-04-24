The Minitalk Project revolves around creating two executables communicating through SIGUSR1 & SIGUSR2 signals. The two programs to create shall be named 
accordingly "server" and "client". As the Subject states, the Server shall print it's Pid at execution and then remain silent in wait for any message to
print: Client on the other hand is to be made to be launched having the server pid as first argument, and the string to send as second argument. 

For the Bonus Part, Unicode texting should be made possible, and the Server shall give back a signal after printing the message. I choose the functions name
after the <a href="https://en.wikipedia.org/wiki/Procedure_word" target="_blank">radio "prowords"</a>.

# What i have learned
First and foremost, this project revolves (first time during my 42 cursus) around 2 arguments: <a href="https://en.wikipedia.org/wiki/Signal_(IPC)" target="_blank">POSIX System Calls (AKA Signals)</a>.

