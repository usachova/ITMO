#!/bin/bash

num=(1,2,3,4,5,6,7,8,9,10)
arr=()

echo "" > report2.log

cnt=0
while true
do
	arr+=(${num[@]})
	let cnt++
	if [[ $cnt == 10000 ]]
	then
		echo "${#arr[@]}" >> report2.log
		cnt=0
	fi
done
