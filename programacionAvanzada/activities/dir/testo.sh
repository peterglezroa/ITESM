#!/bin/bash
echo "./find"
./find 
echo "---------------------------------------------------\n"

echo "./find cha no_existe"
./find cha no_existe
echo "---------------------------------------------------\n"

echo "./find cha find.c"
./find cha find.c
echo "---------------------------------------------------\n"

echo "./find cha dir1 -x"
./find cha dir1 -x
echo "---------------------------------------------------\n"

echo "./find cha dir1"
./find cha dir1
echo "---------------------------------------------------\n"

echo "./find char dir1 -r"
./find char dir1 -r
echo "---------------------------------------------------\n"
