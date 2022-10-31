#!/bin/bash

# run top -d 1
top -d 1

# run ex2 in background and running 'top'
gcc -w ex2.c -o ex2

./ex2 &
top

rm ex2


# Comments

# top:

# When using top, we see a constantly updated perspective of the system being used. 
# A list of processes and/or threads in the kernel mode of the system is displayed. 
# We also see the time, sequence and amount of information provided for the processes, 
# as well as the types of summary information displayed about the system, are configured by the user, 
# and this parameter can be saved during restarts.


# top -d 1:

# top -d 1 - mean that we use top command with delay-time interval of 1 second.
# All information is as well as in a simple top only the frequency of updates fixed in 1 second.