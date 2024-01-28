#!/bin/bash

read -p "Enter the number of terms: " num_terms

# Check if the input is a positive integer
if ! [[ $num_terms =~ ^[1-9][0-9]*$ ]]; then
    echo "Please enter a positive integer."
    exit 1
fi

# Initialize variables for Fibonacci sequence
a=0
b=1

echo "Fibonacci series up to $num_terms terms:"
echo -n "$a $b "

for (( i=3; i<=num_terms; i++ ))
do
    next=$((a + b))
    echo -n "$next "
    a=$b
    b=$next
done

echo ""  # Print newline after the series
