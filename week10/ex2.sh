#!/bin/bash

touch ../week1/file.txt
echo "Lorem Ipsum from Arina" > ../week1/file.txt

link ../week1/file.txt _ex2.txt

inode=$(stat -c '%i' _ex2.txt)
echo "find" > ex2.txt
find ../ -inum ${inode[0]} >> ex2.txt

echo "find -exec rm" >> ex2.txt
find ../ -inum ${inode[0]} -exec rm -v {} \; >> ex2.txt