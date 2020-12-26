#!/bin/bash

mkfifo pipe
bash 5o.sh&
bash 5g.sh
rm pipe
