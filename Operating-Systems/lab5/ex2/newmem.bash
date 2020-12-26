#!/bin/bash

num=(1,2,3,4,5,6,7,8,9,10)
arr=()

if [[ $# == 0 ]]
then
	n=1000000
else
	n=$1
fi

while true
do
	arr+=(${num[@]})
	if [ "${#arr[@]}" -gt "$n" ]
	then
		exit 0
	fi
done

