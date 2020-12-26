#!/bin/bash

d=$(date +"%d.%m.%y_%H:%M:%S")

mkdir ~/test && echo "catalog test was created successfully" >> ~/report && touch ~/test/$d
ping -c1 www.net_nikogo.ru || echo "$d error" >> ~/report
