#!/bin/bash

com="+"
ans=1

st() {
	echo "finish"
	exit 0
}

u1() {
	com="+"
}

u2() {
	com="*"
}

trap 'st' SIGTERM
trap 'u1' USR1
trap 'u2' USR2

while true
do
		case "$com" in
			"+")
				ans=$(($ans + 2))
				echo "$ans"
			;;
			"*")
				ans=$(($ans * 2))
				echo "$ans"
			;;
		esac
		sleep 1
done
