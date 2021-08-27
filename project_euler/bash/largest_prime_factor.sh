#!/usr/bin/env bash

declare -i number=$1
# declare -a factors
declare -i factor
declare -i last_factor
# declare -a primes

if ((number%2 == 0)); then
    number=$((number/2))
    last_factor=2
    while ((number%2 == 0)); do
	number=number/2
    done
else
    last_factor=1
fi

factor=3
while ((number>1)); do
    if ((number%factor == 0)); then
	number=$((number/factor))
	last_factor=factor
	while ((number%factor == 0)); do
	    number=$((number/factor))
	done
    fi
    factor=factor+2
done

# for ((i=2;i<limit;i++)); do
#     prime=true
#     if ! ((limit%i)); then
#	# factors+=($i)
#	for ((j=2;j<i;j++)); do
#	    if ! ((i%j)); then
#		prime=false
#	    fi
#	done
#	if $prime; then
#	    primes+=($i)
#	fi
#     fi
# done

# echo ${factors[@]}
# echo ${primes[@]}
echo $last_factor
