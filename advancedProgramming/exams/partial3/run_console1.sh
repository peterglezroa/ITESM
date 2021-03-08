#!/bin/bash
if test $# -ne 1
then
  echo "Se debe de dar el tamaño del tarro como argumento!"
else
  gcc create.c -o pot
  gcc bees.c -o bees
  gcc bear.c -o bear
  ipcs
  ./pot $1
  ./bear
fi
