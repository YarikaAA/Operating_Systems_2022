#!/bin/bash

gcc -w ex1.c -o ex1
for (( i = 0; i < 3; i++ )); do
    ./ex1 >> ex1.txt
done

rm ex1