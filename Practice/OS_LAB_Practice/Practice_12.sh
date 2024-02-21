# Using 'expr', 'wc' and 'bc'

result=$(expr 5 + 5)
echo "Result: $result"

# Using 'bc' to perform floating point arithmetic

float_re=$(echo "5.5 + 5.5" | bc)
# make sure to install bc package (in case of command not found) 
echo "Result: $float_re"

# Using 'wc' to count the number of lines in a file

lines=$(wc -l < main.sh) # -l is used to count the number of lines
echo "Number of lines in main.sh: $lines"
