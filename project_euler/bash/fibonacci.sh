#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

declare -i limit=$1
declare -i sum
declare -i a=1
declare -i b=1
declare -a fibnums=($a)

while ((b<limit)); do
    if !((b%2)); then
	sum+=$b
    fi
    c=$((a+b))
    a=$b
    b=$c
    fibnums+=($a)
done

echo ${fibnums[@]}
echo $sum
