# Exercise description:
#   1. Create a directory “week1” in home directory.
#   2. List last 5 entries in /usr/bin that contain “gcc” in reverse
#	alphabetical order. Save results in “∼/week1/ex1.txt”.

# Solution:

mkdir ~/week1
cd ~/week1
ls /usr/bin/ | grep gcc | sort -r | tail -n 5 > ~/week1/ex1.txt
