#!/bin/bash

rm ex4.txt

n=10000000
m=(1 2 4 10 100)

gcc -w ex4.c -pthread -o ex4

for i in ${m[@]}; do
	echo "For n = $n m = $i, numbers of primes number is " >> ex4.txt
	(time ./ex4 $n $i) >> ex4.txt 2>&1
	echo "" >> ex4.txt
done

rm ex4