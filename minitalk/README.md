The Minitalk Project revolves around creating two executables communicating through SIGUSR1 & SIGUSR2 signals. The two programs to write shall be named 
accordingly: "server" and "client". As the Subject states, the Server shall print it's Pid at execution and then remain silent in wait for any message to
print: Client on the other hand is to be made to be launched having the server pid as first argument, and the string to send as second argument. 

For the Bonus Part, Unicode texting should be made possible, and the Server shall give back a signal after printing the message, and the client shall be made to receive back that end of transmission message. I choose the functions names
after the <a href="https://en.wikipedia.org/wiki/Procedure_word" target="_blank">radio "prowords"</a>.

# What i have learned
First and foremost, this project revolves (first time during my 42 cursus) around 2 arguments: <a href="https://en.wikipedia.org/wiki/Signal_(IPC)" target="_blank">POSIX System Calls & Signals</a>, and <a href="https://en.wikipedia.org/wiki/Bitwise_operation" target="_blank">bitwise operators</a>. Especially the latter, though, introduced me first time to bit level manipulation in general. Even though learning and replicating the use of operators blindly would have me brought to skip through this project in a matter of hours, possibly a couple of days, i used this project as an excuse to dive deeper in memory rapresentation and binary logic behind the memory use, both from the compiler's and the system point of view.

After managing to grasp the difference between "signal" and "sigaction" functions (the latter being a little bit harder to grasp due to harsher documentation &&|| more complex behaviour and features), i managed to create a basic couple of files capable of communicating to each other. Since the project limits the scope of usable signals to SIGUSR1 & SIGUSR2, i then started to experiment a bit with bit (wink wink) manipulation. As stated above, even though the final solution came in the form of a simple while loop sending bits one by one in reverse order to the server, i forced myself at first to solve the "deconstruction" of the "char" to send by the use of a recursion. For to be sure i was doing the thing correctly, and understand the effects on what i was doing on the bit, i created an ft_printbits function and added it into my library, i then proceded adding this function in my ft_printf.

Only by trying to solve this little task through recursion and simple math, i realized a few things:

1- I realized how chars are handled by the compiler, especially in strings.

2- By forcing myself to do math operations on binary representation of the bits, i learned (or better grasped) how bits and Bytes are needed by Types, and why.

3- I realized that the sign is not solely a simmetrical addition to the more significant bit. 

4- I learned how UNICODE characters are handled by the terminal itself, and how so. This especially i realized is something not to underestimate and i am glad to have dived deep enough to understand the conversion logic of signed bytes into printable characters.

# What i have improved
By the end of this project i improved my library, adding a function to print in bits, then adding my ft_printf too, and consequently improved my ft_printf to introduce 3 different placeholders to print 8, 16, and 32 bits starting from a pointer address. ***I realize that this feature could induce some safety issues in the code basing the operation on shifts rather than mathematical abstraction, and i plan to add countermeasures to mitigate this in the future. Realistically, i will further improve my library in the next project "solong", where this comment will find a development***

My understanding of Mikefiles too had improved during this time, ad by this time i created a better Makefile, silencing useless outputs, and assigning more coherent arguments to it's tasks.
