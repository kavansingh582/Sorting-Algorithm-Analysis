#!/bin/zsh
g++ main.cpp -o default
# Define the file to run
file_to_run="./default"

# Define the inputs
inputs=("0" "1" "2" "3" "4" "5" "6" "7")
files=("reverseNums100" "reverseNums1k" "reverseNums10k" "reverseNums50k" "reverseNums100k" "reverseNums200k" "reverseNums300k" "reverseNums400k" "reverseNums500k" "reverseNums600k" "reverseNums700k" "reverseNums800k" "reverseNums900k" "reverseNums999k")

# Loop through the inputs
for files in "${files[@]}";
	for input in "${inputs[@]}"; do
		# Run the file 5 times for each input
		for i in {1..5}; do
			echo "Running file with input: $input (run $i)"
			$file_to_run "$input" $files
		done
	done
done
