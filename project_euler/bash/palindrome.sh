#!/usr/bin/env bash

# brute force!
declare -i i j largest

for ((i=999; i>=100; i--)); do
    for ((j=999; j>=i; j--)); do

	result=$((i*j))
	reverse=$(echo $result | rev)

	if ((result<largest)); then
	    break
	fi

	if [[ $result == $reverse ]]; then
	    largest=$result
	    I=$i
	    J=$j
	fi
    done
done

echo "$I x $J = $largest"
