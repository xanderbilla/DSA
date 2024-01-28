#!/bin/bash

# Define correct username and password
correct_username="user"
correct_password="pass123"

# Prompt user for username and password
read -p "Enter username: " username
read -sp "Enter password: " password
echo

# Check if username and password are correct
if [ "$username" == "$correct_username" ] && [ "$password" == "$correct_password" ]; then
    echo "Access granted."
else
    echo "Access denied."
fi
