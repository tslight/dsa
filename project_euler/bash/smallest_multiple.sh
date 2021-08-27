#!/usr/bin/env bash

i=20
while ((i>=20)); do

    for ((j=1; j <= 20; j++)); do

	if ((i%j == 0)); then
	    multiple=true
	else
	    multiple=false
	    break
	fi

    done

    if $multiple; then
	echo "Multiple found at $i"
	break
    fi

    ((i++))
done
