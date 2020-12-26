#!/bin/bash

func() {
	find /proc -maxdepth 2 -type f -name "io" -exec grep -isH "rchar" {} \; | sort -nk2
}

func > 1.temp
sleep 1m
func > 2.temp

cat 1.temp |
while read str
do
	pid=$(awk -F"/" '{print $3}' <<< $str)
	mem1=$(awk '{print $2}' <<< $str)
	mem2=$(grep -s "/$pid/" 2.temp | awk '{print $2}')
	diff=$(echo "$mem2-$mem1" | bc)
	echo $pid $diff
done | sort -nk2 | tail -n 3 | awk '{print $1" : "$2}'

rm *.temp
