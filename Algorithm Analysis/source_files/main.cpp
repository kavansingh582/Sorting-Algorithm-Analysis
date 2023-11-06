#include <fstream>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <chrono>
#include "sorting.cpp"
using namespace std;

enum SORT { INSERTION = 0, SELECTION = 1, BUBBLE = 2, MERGE = 3, HEAP_SORT = 4, QUICK = 5, RADIX = 6, COUNTING = 7 };

[[nodiscard]] int* timing(int select, int* arr, int size) {
	int* newArr = new int[size];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	auto start = chrono::high_resolution_clock::now();
	if (select == INSERTION) {
		insertionSort(newArr, size);
	}
	else if (select == SELECTION) {
		selectionSort(newArr, size);	
	}
	else if (select == BUBBLE) {
		bubbleSort(newArr, size);	
	}
	else if (select == MERGE) {
		mergeSort(newArr, size);
	}
	else if (select == HEAP_SORT) {
		HeapSort(newArr, size);
	}
	else if (select == QUICK) {
		quickSort(newArr, getMin(newArr, size), getMax(newArr, size));
	}
	else if (select == RADIX) {
		radixSort(newArr, size);	
	}
	else if (select == COUNTING) {
		countSort(newArr, size, 1); 
	}
	else {
		throw runtime_error("This should not have happened. Invalid input!\n");
	}
	auto end = chrono::high_resolution_clock::now();

	auto time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "Time to sort " << size << " elements " << time << " milliseconds." << endl;

	return newArr;
	delete[] newArr;
}

int main(int argc, char **argv) {
	const size_t SIZE = 1000000; 
	int sortAlgo = 0; // Choice of sorting algorithm
	string filename;
	if (argc > 2) sortAlgo = atoi(argv[1]); //Read mode from command line parameters
											//If no command line parameter (a.out 0 or a.out 1) is provided, then read from keyboard
	else {
		cout << "Choose mode:\n0) Insertion Sort\n1) Selection Sort\n2) Bubble Sort\n3) Merge Sort\n4) Heap Sort\n5) Quick Sort\n6) Radix Sort\n7) Counting Sort\n";
		cin >> sortAlgo;
		if (!cin) throw runtime_error("Invalid selection or value.\n");
		if (sortAlgo < INSERTION or sortAlgo > COUNTING) return EXIT_SUCCESS;
		cout << "Please enter the file you want to open: " << endl;
		cin >> filename;
		if (!cin) throw runtime_error("Invalid value.\n");
	}
	cout << "Sorting Algorithm: " << sortAlgo << endl;
	// If someone doesn't choose a valid choice on the menu, set the sorting algorithm to Insertion Sort.
	if (sortAlgo < INSERTION or sortAlgo > COUNTING) sortAlgo = INSERTION;
	//cerr << "ALGORITHM == " << sortAlgo << endl;
	fstream file;
	if (argc == 1) file.open(filename);
	else file.open(argv[2]);
	if (!file) throw runtime_error("Invalid file passed in!\n");

	int nums[SIZE];
	int resizer = 0;

	for (int i = 0; i < SIZE; i++) {
		int x = 0;
		file >> x;
		if (!file) break;
		nums[i] = x;
		//cout << "nums[" << i << "] = " << nums[i] << endl; 
		resizer++;
	}
	cout << "Size of array: " << resizer << endl;
	int* newArr = new int[resizer];
	for (int i = 0; i < resizer; i++) {
		newArr[i] = nums[i];
		//cout << "newArr[" << i << "] = " << newArr[i] << endl; 
	}

	if (sortAlgo == INSERTION) {
		cerr << "Insertion" << endl;
		newArr = timing(INSERTION, newArr, resizer);
		//printArray(newArr, resizer);
	}
	else if (sortAlgo == SELECTION) {
		cerr << "Selection" << endl;
		newArr = timing(SELECTION, newArr, resizer);
		//printArray(newArr, resizer);
	}
	else if (sortAlgo == BUBBLE) {
		cerr << "Bubble" << endl;
		newArr = timing(BUBBLE, newArr, resizer);
		//printArray(newArr, resizer);
	}
	else if (sortAlgo == MERGE) {
		cerr << "Merge Sort" << endl;
		newArr = timing(MERGE, newArr, resizer);
		//printArray(newArr, resizer);
	}
	else if (sortAlgo == HEAP_SORT) {
		cerr << "Heap Sort" << endl;
		newArr = timing(HEAP_SORT, newArr, resizer);
		//printArray(newArr, resizer);
	}
	else if (sortAlgo == QUICK) {
		cerr << "Quick" << endl;
		newArr = timing(QUICK, newArr, resizer);
		//printArray(newArr, resizer);
	}
	else if (sortAlgo == RADIX) {
		cerr << "Radix" << endl;
		newArr = timing(RADIX, newArr, resizer);
		//printArray(newArr, resizer);
	}
	else if (sortAlgo == COUNTING) {
		cerr << "Counting" << endl;
		newArr = timing(COUNTING, newArr, resizer);
		//printArray(newArr, resizer);
	}
	else {
		throw runtime_error("This shouldn't have happened. Possible invalid input.\n");
	}
	delete[] newArr; //TODO: Properly fix memory leak
	return EXIT_SUCCESS;
}
