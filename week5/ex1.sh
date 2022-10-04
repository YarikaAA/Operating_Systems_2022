#!/bin/bash

n=4

gcc -w publisher.c -o publisher && gcc -w subscriber.c -o subscriber

for (( i = 0; i < n; i++ )); do
	gnome-terminal -- ./subscriber
done

./publisher ${n}

rm publisher
rm subscriber