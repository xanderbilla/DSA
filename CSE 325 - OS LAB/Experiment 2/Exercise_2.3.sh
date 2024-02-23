#!/bin/bash

is_prime() {
    local num=$1
    if [ $num -le 1 ]; then
        return 1
    fi
    for (( i=2; i*i<=num; i++ ))
    do
        if [ $((num % i)) -eq 0 ]; then
            return 1
        fi
    done
    return 0
}

read -p "Enter a number to check if it's prime: " user_num

if ! [[ $user_num =~ ^[1-9][0-9]*$ ]]; then
    echo "Please enter a positive integer."
    exit 1
fi

is_prime $user_num

if [ $? -eq 0 ]; then
    echo "$user_num is a prime number."
else
    echo "$user_num is not a prime number."
fi
