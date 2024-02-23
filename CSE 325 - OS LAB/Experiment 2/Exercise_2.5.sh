#!/bin/bash

# Prompt user for directory path
read -p "Enter directory path: " directory

# Check if directory exists
if [ ! -d "$directory" ]; then
    echo "Directory not found."
    exit 1
fi

# Display all files in the directory
echo "Files in directory $directory:"
for file in "$directory"/*
do
    if [ -f "$file" ]; then
        echo "$file"
    fi
done
