#!/bin/bash

# switch case - calculator

read -p "Enter a number: " choice

select choice in "Add" "Sub" "Mul" "Div" "Exit"

do
    case $choice in
        "Add")
            read -p "Enter two numbers: " a b
            echo "Sum: $((a+b))"
            ;;
        "Sub")
            read -p "Enter two numbers: " a b
            echo "Difference: $((a-b))"
            ;;
        "Mul")
            read -p "Enter two numbers: " a b
            echo "Product: $((a*b))"
            ;;
        "Div")
            read -p "Enter two numbers: " a b
            echo "Quotient: $((a/b))"
            ;;
        "Exit")
            break
            ;;
        *)
            echo "Invalid choice"
            ;;
    esac
done

