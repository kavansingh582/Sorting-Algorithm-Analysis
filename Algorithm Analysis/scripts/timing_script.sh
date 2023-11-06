#!/bin/zsh
g++ main.cpp -o default
# Define the file to run
file_to_run="./default"

# Define the inputs
inputs=("0" "1" "2" "3" "4" "5" "6" "7")
files=("randomNum100" "randomNum1k" "randomNum10k" "randomNum50k" "randomNum100k" "randomNum200k" "randomNum300k" "randomNum400k" "randomNum500k" "randomNum600k" "randomNum700k" "randomNum800k" "randomNum900k" "randomNum999k")

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
