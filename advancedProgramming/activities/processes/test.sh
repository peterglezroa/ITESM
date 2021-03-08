#!/bin/bash

cal=10

echo "gcc $1"
gcc $1
if [[ $? -ne 0 ]] ; then 
	echo "grade: $cal"
	exit 1
fi

echo "./a.out"
./a.out
if [[ $? -ne 254 ]] ; then 
	echo "grade: $cal"
	exit 1
fi
cal=$((cal+10))

echo "./a.out texto"
./a.out texto
if [[ $? -ne 253 ]] ; then 
	echo "grade: $cal"
	exit 1
fi

echo "./a.out -10"
./a.out -10
if [[ $? -ne 253 ]] ; then 
	echo "grade: $cal"
	exit 1
fi

echo "./a.out 0"
./a.out 0
if [[ $? -ne 253 ]] ; then 
	echo "grade: $cal"
	exit 1
fi
cal=$((cal+10))

echo "./a.out 3"
./a.out 3
if [[ $? -ne 0 ]] ; then 
	echo "grade: $cal"
	exit 1
fi
cal=$((cal+70))

echo "=>grade: $cal"
