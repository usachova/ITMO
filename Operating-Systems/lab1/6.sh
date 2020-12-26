#!/bin/bash

ww="$(awk '$3 == "(WW)"' /var/log/anaconda/X.log)"
ii="$(awk '$3 == "(II)"' /var/log/anaconda/X.log)"

exec > full.log
echo "${ww//"(WW)"/"Warnings:"}"
echo "${ii//"(II)"/"Information:"}"

exec > /dev/tty
cat full.log
