#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

declare -a num
declare -i input=$1
declare -i total=0

for ((i=1; i<input; i++)); do
    if !((i%3 && i%5)); then
	num+=($i)
	total=$((total+$i))
    fi
done

echo $total
