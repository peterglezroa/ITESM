#!/bin/bash
if test $# -ne 1
then
  echo "Se debe de dar la cantidad de abejas como argumento"
else
  ./bees $1
fi
