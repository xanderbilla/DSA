#!/bin/bash

# Print the numbers from n to 1 using while loop

read -p "Enter the number: " n

while [ $n -gt 0 ]
do
    echo -n "$n "
    let n--
done
echo " "