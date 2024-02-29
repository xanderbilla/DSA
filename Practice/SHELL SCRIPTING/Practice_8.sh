#!/bin/bash

# print an array using for loop

arr=("vikas" 20.2 "University" 325)

for table in ${arr[@]}
do
    echo $table
done