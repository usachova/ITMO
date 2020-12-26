#!/bin/bash

nice -n 10 bash 4t.sh&
nice -n 1 bash 4t.sh&
nice -n 0 bash 4t.sh&
