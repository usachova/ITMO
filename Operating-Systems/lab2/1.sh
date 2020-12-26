#!/bin/bash

ps -u user -o pid,command | awk '{ if($2 != "COMMAND") print $1 }' | wc -l > ans1
ps -u user -o pid,command | awk '{ if($2 != "COMMAND") print $1, ":", $2 }'  >> ans1
