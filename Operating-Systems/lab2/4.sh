#!/bin/bash

for dir in $(ps -A -o pid)
do
	statf="/proc/"$dir"/status"
	schf="/proc/"$dir"/sched"
	pid=$(grep -Ehsi "^Pid:" $statf | awk '{ print $2 }')
	ppid=$(grep -Ehsi "^PPid:" $statf | awk '{ print $2 }')
	ser=$(grep -Ehsi "se.sum_exec_runtime" $schf | awk '{ print $3 }')
	ns=$(grep -Ehsi "nr_switches" $schf | awk '{ print $3 }')
	if [[ -z $ppid ]]
		then ppid=0
	fi
	if [[ -z $ns ]]
		then continue;
	fi
	ART=$(echo "scale=6; $ser/$ns" | bc | awk '{ printf "%f", $0 }')
	echo "$pid $ppid $ART"
done | sort -nk2 | awk '{print "ProcessID="$1" : Parent_ProcessID="$2" : Average_Running_Time="$3}' > ans4
