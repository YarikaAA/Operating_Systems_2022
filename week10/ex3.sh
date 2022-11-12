#!/bin/bash

touch _ex3.txt
echo "Lorem Ipsum from Arina" > _ex3.txt

chmod -vv a-x _ex3.txt > ex3.txt
chmod -vv uo+rwx _ex3.txt >> ex3.txt
chmod -vv g=u _ex3.txt >> ex3.txt 

echo >> ex3.txt
echo "Answers:" >> ex3.txt
echo "660 sets owner=rw- group=rw- other=---" >> ex3.txt
echo "775 sets owner=rwx group=rwx other=-wx" >> ex3.txt
echo "777 sets owner=rwx group=rwx other=rwx" >> ex3.txt

rm _ex3.txt