#/usr/bin/env bash
# This script sends a quit signal to process ID
if [ $# -eq 0 ]
    then
        echo "Usage: $0 <pid>"
        exit 1
fi
kill -s 3 $1
