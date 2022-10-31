#!/bin/bash

gcc -w ex2.c -o ex2

./ex2 &
vmstat 1

rm ex2