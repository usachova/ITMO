#!bin/bash

str=""
while [[ "$str" != "q" ]]
do
	res_str+="$str"
	read str
done
echo "$res_str""q"
