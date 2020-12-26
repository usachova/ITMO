#!/bin/bash

grep "VmRSS" /proc/*/status | sed "s/[^0-9]\+/ /g"| sed "s/^ //" | sort -nrk2 | head -1 | awk '{print "pid: "$1" mem: "$2}'
top -o %MEM | head -8 | tail -n +8
