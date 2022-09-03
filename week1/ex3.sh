# Exercise description:
#   1. Write a shell script ex3.sh that creates two files (root.txt, home.txt)
#	inside two separate new folders
#   2. Before creating the next item (file or folder), print the date and wait for 3 seconds
#   3. The file root.txt contains the items of the root directory ‘/’
#   4. The file home.txt contains the items of the home directory ‘∼’
#   5. The items of both directories should be sorted by time (oldest first)
#   6. Print the content of files and display items of your new folders.



# Solution:

mkdir ~/week1/root
date
sleep 3
mkdir ~/week1/home
ls -l -rt / > ~/week1/root/root.txt
date
sleep 3
ls -l -rt ~ > ~/week1/home/home.txt
less ~/week1/root/root.txt
less ~/week1/home/home.txt
ls ~/week1/root & ls ~/week1/home
