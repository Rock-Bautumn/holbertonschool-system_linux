#!/bin/bash

readelf -W -h $1 > TESTOUT_readelf1.txt
make 1-hreadelf | grep -v "up to date"
./1-hreadelf $1 > TESTOUT_task1.txt
diff -sy TESTOUT_readelf1.txt TESTOUT_task1.txt
