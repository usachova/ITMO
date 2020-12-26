#!/bin/bash

sum=0
cnt=0
par=0

echo "_" >> ans4
exec < ans4

while read str
do
	str=$(echo $str | sed "s/[^0-9.]\+/ /g" | sed "s/^ //g")
	ppid=$(echo $str | awk '{print $2}')
	ART=$(echo $str | awk '{print $3}')
	if [[ $ppid != $par ]]
	then
		if [[ $cnt != 0 ]]
		then
			x=$(echo "scale=6; $sum/$cnt" | bc | awk '{printf "%f", $0}')
			echo "Average_Sleeping_Children_of_ParentID="$par" is "$x
		fi
		par=$ppid
		cnt=1
		sum=$ART
	else
		sum=$(echo "scale=6; $sum+$ART" | bc | awk '{printf "%f", $0}')
		cnt=$(($cnt+1))
	fi
	pid=$(echo $str | awk '{print $1}')
	if [[ -n $pid ]]
	then
		echo "ProcessID="$pid" : Parent_ProcessID="$ppid" : Average_Running_Time="$ART
	fi
done > ans5
exec < /dev/tty
sed -i "$ d" ans4
