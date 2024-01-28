#!/bin/bash

# Function for addition
add() {
    result=$(($1 + $2))
    echo "Result: $result"
}

# Function for subtraction
subtract() {
    result=$(($1 - $2))
    echo "Result: $result"
}

# Function for multiplication
multiply() {
    result=$(($1 * $2))
    echo "Result: $result"
}

# Function for division
divide() {
    if [ $2 -eq 0 ]; then
        echo "Error: Division by zero."
    else
        result=$(($1 / $2))
        echo "Result: $result"
    fi
}

# Display menu
echo "Menu:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"

# Prompt user for choice
read -p "Enter your choice: " choice

# Perform operation based on user's choice
case $choice in
    1)
        read -p "Enter first number: " num1
        read -p "Enter second number: " num2
        add $num1 $num2
        ;;
    2)
        read -p "Enter first number: " num1
        read -p "Enter second number: " num2
        subtract $num1 $num2
        ;;
    3)
        read -p "Enter first number: " num1
        read -p "Enter second number: " num2
        multiply $num1 $num2
        ;;
    4)
        read -p "Enter first number: " num1
        read -p "Enter second number: " num2
        divide $num1 $num2
        ;;
    *)
        echo "Invalid choice."
        ;;
esac
