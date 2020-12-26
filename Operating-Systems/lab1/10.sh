#!/bin/bash

man bash | grep -i -o "\b[a-zA-Z]\{4,\}\b" | tr "[:upper:]" "[:lower:]" | sort | uniq -c | sort -n -r | head -3 | awk '{print $2}'
