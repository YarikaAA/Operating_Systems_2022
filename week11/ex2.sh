#!/bin/bash

sudo chmod 776 lofsdisk

touch lofsdisk/file1.txt
touch lofsdisk/file2.txt

echo "Arina" > lofsdisk/file1.txt
echo "Yartseva" > lofsdisk/file2.txt

gcc -w ex2.c -o ex2.out

mkdir -p lofsdisk/bin
mkdir -p lofsdisk/lib/x86_64-linux-gnu
mkdir -p lofsdisk/lib64

cp /bin/bash lofsdisk/bin/bash
cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu/libc.so.6
cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/ld-linux-x86-64.so.2
cp ex2.out lofsdisk/ex2.out


sudo chroot lofsdisk ./ex2.out > ex2.txt
./ex2.out >> ex2.txt

rm ex2.out