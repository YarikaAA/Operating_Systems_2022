#!/bin/bash

n=10000000
m=(1 2 4 10 100)

gcc -w ex3.c -pthread -o ex3

for i in ${m[@]}; do
	echo "For n = $n m = $i, numbers of primes number is " >> ex3.txt
	(time ./ex3 $n $i) >> ex3.txt 2>&1
	echo "" >> ex3.txt
done

rm ex3