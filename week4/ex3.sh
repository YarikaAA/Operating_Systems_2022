gcc -w  ex3.c -o ex3

./ex3 3 &

echo "For 3: "

for i in seq 1 3; do
	pstree $$ -p
	sleep 3;
done

./ex3 5 &

echo "For 5: "

for i in seq 1 5; do
	pstree $$ -p
	sleep 1;
done