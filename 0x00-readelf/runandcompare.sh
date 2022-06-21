#!/bin/bash

readelf -W -h $1 > TESTOUT_readelf.txt
gcc -Wextra -pedantic -Wall -Werror -std=c90 testfile.c -o task1
./task1 $1 > TESTOUT_task1.txt
diff -sy TESTOUT_readelf.txt TESTOUT_task1.txt

