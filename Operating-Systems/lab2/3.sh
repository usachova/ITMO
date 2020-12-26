#!/bin/bash

ps ax -o pid,start_time | awk '{ print $1 }' | tail -1
