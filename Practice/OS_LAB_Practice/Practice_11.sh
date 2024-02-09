#!/bin/bash

# Print the numbers from n to 1 using until loop

read -p "Enter the number: " n

until [ $n -lt 1 ]
do
    echo -n "$n "
    let n--
done
echo " "