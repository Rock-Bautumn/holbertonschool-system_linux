#!/bin/bash

readelf -W -S $1 > TESTOUT_readelf1.txt
make clean && make 1-hreadelf
./1-hreadelf $1 > TESTOUT_task1.txt
diff -sy TESTOUT_readelf1.txt TESTOUT_task1.txt
