#!/bin/bash

# conditional statement - check for the greatest number among three numbers

read -p "Enter the first number: " num1
read -p "Enter the second number: " num2
read -p "Enter the third number: " num3

if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
    echo "$num1 is the greatest number"
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]
then
    echo "$num2 is the greatest number"
else
    echo "$num3 is the greatest number"
fi