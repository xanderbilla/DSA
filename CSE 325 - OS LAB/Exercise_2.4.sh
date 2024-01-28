#!/bin/bash

reverse_number() {
    local num=$1
    local reversed_num=0
    while [ $num -gt 0 ]
    do
        last_digit=$((num % 10))
        reversed_num=$((reversed_num * 10 + last_digit))
        num=$((num / 10))
    done
    echo $reversed_num
}

read -p "Enter a number to reverse: " user_num

if ! [[ $user_num =~ ^[0-9]+$ ]]; then
    echo "Please enter a valid number."
    exit 1
fi

reversed=$(reverse_number $user_num)
echo "Reversed number: $reversed"
