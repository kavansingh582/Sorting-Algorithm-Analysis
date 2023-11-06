    _    _                  _ _   _               
   / \  | | __ _  ___  _ __(_) |_| |__  _ __ ___  
  / _ \ | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \ 
 / ___ \| | (_| | (_) | |  | | |_| | | | | | | | |
/_/   \_\_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|
           |___/                                  
    _                _           _     
   / \   _ __   __ _| |_   _ ___(_)___ 
  / _ \ | '_ \ / _` | | | | / __| / __|
 / ___ \| | | | (_| | | |_| \__ \ \__ \
/_/   \_\_| |_|\__,_|_|\__, |___/_|___/
                       |___/           

This program is to check the algorithm analysis on multiple sorting algorithms
and see the best, average, and worst case runs of each. Throughout this program,
we wanted to encourage users to be able to test their own files and make sure they
can automate the process. Below are the steps to make your own test files, test it
against our sorting algorithms, and utilize the scripts in any case you want to 
benchmark large data sets.

Step 1: Modify generator.cc to build your dataset. 
	► This step is important because the random numbers you generate in this file 
	can influence your algorithm. We had planned on using a better random number
	generator rather than rand() but settled for it because of time. Once you are done
	modifying your dataset, move onto step 2.

Step 2: Run ./file_generator.sh
	► The script ./file_generator.sh utilizes Z shell in Unix, however with slight modifications,
	you can make it work within any shell in Unix. As for Visual Studio, CodeBlocks, and other IDEs,
	I haven't been able to ensure it works with them. As for the script itself, it will build fourteen
	files of random numbers that start from 100 and go to 1 Million. Feel free to modify this script if 
	you want to test different datasets.

Step 3: Compile main.cpp and sorting.cpp
	► main.cpp has sorting.cpp included so you do not need to compile sorting.cpp. If you try to comile both,
	you will get a linker error that looks like this:
		sorting.cpp:(.text+0xdc5): multiple definition of `radixSort(int*, int)'; /tmp/ccx1q8Gw.o:main.cpp:(.text+0xdc5): first defined here                                          collect2: error: ld returned 1 exit status
	The other alternative is to utilize the makefile. There are two options to choose from in the makefile,
	but ensure you do not have an a.out by running "make clean" before compiling with the makefile. To compile
	with the makefile, you have two options: Optimized and NonOptimized. The only difference between the two is 
	I turned the optimizer on (-O3) to see how that would effect runtime. IMPORTANT: The makefile utilizes address
	sanitizer and will report memory leaks during runtime. I encourage you to compile with "g++ -std=c++2a -O3 main.cpp"
	until the memory leak is fixed. Again, there is a KNOWN memory leak so please compile with the flag above.

Step 4: Test your files
	► Once you ensure that the program compiles, you have two options: 1) You can use the script that times or
	2) You can run it manually by running the executable. I will address both briefly.

	► Option 1: If you decide to run the scripts, first know the default script to run is ./timing_script.sh since
	that will utilize the "randomNum" files you built back in step 2. Those files are your "average case". If you want
	best case, you can take your files and run ./sortNums.sh (which utilizes a the program built in sortNums.cpp) and
	builds text files (i.e. sortNum100) that are in sorted order. If you want worst case, the same basic principle as above
	applies. Run ./reverseNums.sh and it will build a file in reverse sorted order. Once you are ready, run one of the three
	scripts: ./timing_script.sh, ./sorted_timing_script.sh, or ./reverse_timing_script.sh. Note that you can pipe the output
	into a text file for later viewing like this: ./timing_script.sh > average_case.txt

	► Option 2: If you want to run the program manually, it is also supported. First, compile the program with
	g++ -std=c++2a -O3 main.cpp -o algorithm. Once you are done, you will run by typing ./algorithm. Once you run
	the program you will get the following prompt:

	Choose mode:
	0) Insertion Sort
	1) Selection Sort
	2) Bubble Sort
	3) Merge Sort
	4) Heap Sort
	5) Quick Sort
	6) Radix Sort                                                                                                                                                 
	7) Counting Sort

	You only have to insert a number 0 through 7. If you insert a number less than 0 or greater than 7, the program quits.
	If you insert the words "Insertion Sort", the program will throw a runtime error like the one below:

	terminate called after throwing an instance of 'std::runtime_error'                                                                                                             what():  Invalid selection or value.

	Once you pass that prompt, you will be asked to insert the file you want to open. Simply type in the file you want
	to test then hit "enter". If the file does not exist, the program will throw a runtime error with this as your message:

	terminate called after throwing an instance of 'std::runtime_error'
	  what():  Invalid file passed in!

	If you pass in a valid file, you will see the following: 

	Please enter the file you want to open:
	randomNum100
	Sorting Algorithm: 3
	Size of array: 100
	Merge Sort
	Time to sort 100 elements 0 milliseconds.

	This means the program executed successfully. If you want to view a printed array, main.cpp has a print_array() function in
	each if statement so you can print the array and check for correctness. If you choose this route, I encourage much smaller
	sizes not exceeding 100 numbers.

Step 5: Look at your data
	► I encorage everyone who utilizes this program to check the times they got after benchmarking to see if the runtime you
	expected is what you see. I utilized the standard library's <chrono> library to do the timing. I used milliseconds because
	that was the most reasonable method I could use to see how long an iteration would take. I could've used nanoseconds but the
	difference between each of those was so miniscule that it wouldn't have made a difference in the grand scheme of the algorithm.
	If you prefer to see the output with nanoseconds, go to my timing() function, head to the bottom and look for the variable "time".
	Replace what is there with this: 

	auto time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

With that, I hope you find our project organized and correct. If you have any questions about this program, feel free to reach out!

==========SAMPLE RUNS==========
Choose mode:
0) Insertion Sort
1) Selection Sort
2) Bubble Sort
3) Merge Sort
4) Heap Sort
5) Quick Sort
6) Radix Sort
7) Counting Sort
0
Please enter the file you want to open:
randomNum1k
Sorting Algorithm: 0
Size of array: 1000
Insertion
Time to sort 1000 elements 1 milliseconds.


Choose mode:
0) Insertion Sort
1) Selection Sort
2) Bubble Sort
3) Merge Sort
4) Heap Sort
5) Quick Sort
6) Radix Sort
7) Counting Sort
6
Please enter the file you want to open:
randomNum50k
Sorting Algorithm: 6
Size of array: 50000
Radix
Time to sort 50000 elements 3 milliseconds.


Choose mode:
0) Insertion Sort
1) Selection Sort
2) Bubble Sort
3) Merge Sort
4) Heap Sort
5) Quick Sort
6) Radix Sort
7) Counting Sort
3
Please enter the file you want to open:
randomNum100k
Sorting Algorithm: 3
Size of array: 100000
Merge Sort
Time to sort 100000 elements 15 milliseconds.
