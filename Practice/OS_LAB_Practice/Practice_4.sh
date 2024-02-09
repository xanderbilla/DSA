#!/bin/bash

# conditional statement - check if number of command line argument is greater than 2

if [ $# -gt 2 ]
then
    echo "You have provided more than 2 command line argument"
else
    echo "You have provided less than 2 command line argument"
fi