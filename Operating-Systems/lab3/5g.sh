#!/bin/bash

while true
do
	read str
	echo "$str" > pipe
	if [[ "$str" == "QUIT" ]]
	then
		echo "finish"
		exit 0
	fi
	if [[ "$str" != "+" && "$str" != "*" && "$str" != [0-9]* ]]
	then
		echo "error"
		exit 1
	fi
done
