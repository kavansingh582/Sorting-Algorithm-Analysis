The problem is to design and implement an efficient algorithm that, given a set S of n integers and another integer x, 
determines whether or not two elements exist in S whose sum is exactly x. There are two algorithms you can choose from. 
A brute force method that compares each element in pairs and goes through the entire list to see if the pair adds up to 
the desired value or an efficient approach where a hash table is used to search the two elements whose sum is x.

Step 1: Insert the size of the array.
▶ The program will prompt the user to insert the array size. Once inputted, a randomly generated array from numbers 0-100 
will be initialized. The array will also be displayed.
        Step 2: Choose a method
                ▶ The user can choose from one of the following options:
       
                     1) Brute Force approach.
                     2) Efficient approach.
                     3) Print Array
                     4) Exit.
                
You can insert numbers from 1-4, if any other number is inserted, the user is asked to select another option. 

If a user chooses 1 or 2, the type of approach will be displayed. Then, the user will be asked to insert the element x, an 
integer in which two elements in the list whose sum equals it.

Step 3: Results
▶ When an approach is picked, two cases occur. If the algorithm finds two values that sum to x, it will print such values and 
record the duration. If the algorithm does not find any values that add to x, the corresponding message will appear: 

“There does not exist two elements in the list whose sum equals the inputted number. Try again”

The duration is still recorded and displayed since this is the worst-case scenario. After each iteration, the user will be asked 
for an approach and then a number x to find. Once the user has gathered their data, simply input 4 and the program will finish.
If a user wants to utilize an array of a different size, then they will have to recompile the program and input a different array 
size from the beginning. The program simply uses the same array during each iteration. 

I used the chrono library and the high_resolution_clock to record the execution time of each function. The recorded time is in 
milliseconds as that is the time used in part one. If a user wants to use nanoseconds, simply replace milliseconds with nanoseconds 
from the line in CSCI 115 Project Pt2.cpp:

auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

With that, I hope you find our project organized and correct. If you have any questions about this program, feel free to reach out!

==========SAMPLE RUNS==========
The array that will be used will have random integers with a range of 0-100
Enter the size of the array you want to test: 10000
Enter a choice:
1) Brute Force approach.
2) Efficient approach.
3) Print array.
4) Exit
1

Testing brute force approach...
Enter an element to find if there are two integers in the list whose sum equals it: 400
There does not exist two elements in the list whose sum equals the inputted number. Try again

Duration in milliseconds: 56

Enter a choice:
1) Brute Force approach.
2) Efficient approach.
3) Print array.
4) Exit
2

Testing efficient approach...
Enter an element to find if there are two integers in the list whose sum equals it: 400
There does not exist two elements in the list whose sum equals the inputted number. Try again

Duration in milliseconds: 15

Enter a choice:
1) Brute Force approach.
2) Efficient approach.
3) Print array.
4) Exit
1

Testing brute force approach...
Enter an element to find if there are two integers in the list whose sum equals it: 145
72 and 73 are two elements that equal 145

Duration in milliseconds: 1

Enter a choice:
1) Brute Force approach.
2) Efficient approach.
3) Print array.
4) Exit
2

Testing efficient approach...
Enter an element to find if there are two integers in the list whose sum equals it: 145
72 and 73 are two elements that equal 145

Duration in milliseconds: 0

Enter a choice:
1) Brute Force approach.
2) Efficient approach.
3) Print array.
4) Exit
4
Exiting...
