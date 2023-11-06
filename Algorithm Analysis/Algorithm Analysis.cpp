#include <iostream>
#include <unordered_set>
#include <chrono>
using namespace std;
using namespace chrono;

int* genArray(int n) { //Generates an array with user input
    int* temp = new int[n]; //Create a temp array to store integers
    srand(time(0));
    for (int i = 0; i < n; i++) { //Store inputted integers
        temp[i] = rand() % 101; //Array will have a range from 0-100
    }
    return temp;
}
bool brute_sum_pair(int S[], int x, int n) {
    for (int i = 0; i < n-1; i++) { //Loop through each pair of indexes till you find two that add up to x
        for (int j = i + 1; j < n; j++) {
            if (S[i] + S[j] == x) {
                cout << S[i] << " and " << S[j] << " are two elements that equal " << x << endl << endl;
                return true;
            }
        }
    }
    return false; //If none is found, return false
}
bool table_sum_pair(int S[], int x, int n) {
    unordered_set<int> hash_table; //Initialize an empty unordered_set
    for (int i = 0; i < n; i++) { //Loop through the inputted array
        int d = x - S[i]; //The difference between x and the current element is the number to look for in the hash table
        if (hash_table.find(d) != hash_table.end()) { //If the d is found, return true
            cout << d << " and " << S[i] << " are two elements that equal " << x << endl << endl;
            return true;
        }
        hash_table.insert(S[i]); //Else insert the element into the unordered_set
    }
    return false; // If none are found, return false
}

void printArray(int* arr, int n) { //Utility function that prints an array
    cout << "Contents of the Array: \n";
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " "; 
    }
    cout << endl;
}

int main() {
    int size, num, choice;
    cout << "The array that will be used will have random integers with a range of 0-100\n";
    cout << "Enter the size of the array you want to test: ";
    cin >> size;
    int* arr = genArray(size); //Initialize array

    do {
        //User is allowed a choice between each method or exit
        cout << "Enter a choice: \n";
        cout << "1) Brute Force approach.\n"
             << "2) Efficient approach. \n"
             << "3) Print array.\n"
             << "4) Exit\n";
        cin >> choice;

        steady_clock::time_point start;
        steady_clock::time_point end;

        if (choice == 1) { //Brute force approach
            cout << "\nTesting brute force approach...\n";
            cout << "Enter an element to find if there are two integers in the list whose sum equals it: ";
            cin >> num;
            start = chrono::high_resolution_clock::now();
            if (brute_sum_pair(arr, num, size)) {
                end = chrono::high_resolution_clock::now(); //Ends clock
            }
            else {
                end = chrono::high_resolution_clock::now(); //Ends clock
                cout << "There does not exist two elements in the list whose sum equals the inputted number. Try again\n\n";
            }
        }
        else if (choice == 2) { //Efficient approach
            cout << "\nTesting efficient approach...\n";
            cout << "Enter an element to find if there are two integers in the list whose sum equals it: ";
            cin >> num;
            start = chrono::high_resolution_clock::now();
            if (table_sum_pair(arr, num, size)) {
                end = chrono::high_resolution_clock::now(); //Ends clock
            }
            else {
                end = chrono::high_resolution_clock::now(); //Ends clock
                cout << "There does not exist two elements in the list whose sum equals the inputted number. Try again\n\n";
            }
        }
        else if (choice == 3) { //Printing Array
            printArray(arr, size);
            cout << endl;
        }
        else if (choice == 4) { //Exit
            cout << "Exiting...\n";
            break;
        }
        else //Default statement
            cout << "ERROR: Choice is not one of the options. Try Again\n\n";
    
        if (choice < 3) { //Do not output duration for the first 3 choices
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count(); //Duration of a function
            cout << "Duration in milliseconds: " << duration << endl << endl;
        }
    } while (true);

    return 0;
}
