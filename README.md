# cecs326Lab1
In this lab, we were tasked with demonstrating what happens when concurrently executed threads access shared
variables without proper synchronization. Later, the mutex synchronization primitives
in Pthreads were added to achieve proper synchronization.

From the instructions in the lab, we were able to write code that simulates and expresses what goes on when threads
are executed concurrently.

In order to execute the file, in the Ubuntu Virtual Machine, after having downloaded the file and saved it onto said
Virtual Machine, the following code was executed in a Terminal window in order to demonstrate this lab.

cd Downloads

gcc multithread.c -o  multithread -pthread

./multithread # (with the # sign representing any integer value input into that line)
