#!/bin/zsh
g++ main.cpp -o default
# Define the file to run
file_to_run="./default"

# Define the inputs
inputs=("0" "1" "2" "3" "4" "5" "6" "7")
files=("sortNum100" "sortNum10k" "sortNum50k" "sortNum100k" "sortNum200k" "sortNum300k" "sortNum400k" "sortNum500k" "sortNum600k" "sortNum700k" "sortNum800k" "sortNum900k" "sortNum999k")

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
