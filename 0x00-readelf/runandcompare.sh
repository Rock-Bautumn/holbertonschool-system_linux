#!/bin/bash

readelf -W -h $1 > TESTOUT_readelf.txt
make 0-hreadelf | grep -v "up to date"
./0-hreadelf $1 > TESTOUT_task0.txt
diff -sy TESTOUT_readelf.txt TESTOUT_task0.txt
