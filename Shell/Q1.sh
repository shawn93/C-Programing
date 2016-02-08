#!/bin/sh
sort -n -r -k 3 -t '|' $2 | sed -n $1'p' | awk -F "|" '{print $1}'