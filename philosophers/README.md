Philosophers is a project concerning concurrent algorithm design, splitting a job and handling resources in a sensible way. The pretext of this task is to simulate the <a href="https://en.wikipedia.org/wiki/Dining_philosophers_problem" target="_blank">Dining Philosophers Problem</a>.

Mandatory part expects you to assign a philosopher's routine to a <a href="https://it.wikipedia.org/wiki/POSIX_Threads" target="_blank"> POSIX thread</a>, and protect each <a href="https://en.wikipedia.org/wiki/Critical_section" target="_blank"> crytical section </a> with a designated <a href="https://en.wikipedia.org/wiki/Lock_(computer_science)" target="_blank"> POSIX MUTEX </a>.

The bonus project is about achieving the same result by creating a separate Process for each Philosopher, and handling critical sections and mutual exclusions through <a href="https://www.geeksforgeeks.org/use-posix-semaphores-c/" target="_blank">POSIX Semaphores</a>.
