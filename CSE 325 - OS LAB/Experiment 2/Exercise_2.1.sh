#!/bin/bash

# Prompt the user for input
read -p "Enter a number: " num

# Initialize sum variable
sum=0

# Loop from 1 to the user-provided number and calculate the sum
for (( i=1; i<=num; i++ ))
do
    sum=$((sum + i))
done

# Print the result
echo "The sum of numbers from 1 to $num is: $sum"
