#!/bin/bash

readelf -W -h $1 > TESTOUT_readelf0.txt
make 1-hreadelf | grep -v "up to date"
./1-hreadelf $1 > TESTOUT_task0.txt
diff -sy TESTOUT_readelf0.txt TESTOUT_task0.txt
