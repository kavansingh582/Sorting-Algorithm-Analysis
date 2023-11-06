#pragma once
#include <iostream>

using namespace std;
//Utility Functions
//Get Max/Min
int getMin(int a[], int n){
	int min = a[0];
	for (int i = 1; i<n; i++){ //Loop through array updating min when a number is larger than current min
		if (a[i] < min){
			min = a[i];
		}
	}
	return min;
}
int getMax(int a[], int n){
	int max = a[0];
	for (int i = 1; i<n; i++){ //Loop through array updating max when a number is larger than current max
		if (a[i] > max){
			max = a[i];
		}
	}
	return max;
}
//Printing array
void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}
//Swap
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
//Insertion
void insertionSort(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j])
		{
			swap(&arr[j], &arr[j - 1]);
			j -= 1;
		}
	}
}
//Selection 
void selectionSort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++)
	{
		int minloc = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minloc])
				minloc = j;
		}
		if (minloc != i)
			swap(&arr[i], &arr[minloc]);
	}
}
//Bubble 
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			// Swap if the element found is greater than the next element
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//Merge sort
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
	int i = 0; // Index for left subarray
	int j = 0; // Index for right subarray
	int k = 0; // Index for merged array

	// Compare elements from left and right subarrays and merge
	while (i < leftSize && j < rightSize) {
		if (left[i] < right[j]) {
			arr[k++] = left[i++];
		} else {
			arr[k++] = right[j++];
		}
	}

	// Copy remaining elements from left subarray, if any
	while (i < leftSize) {
		arr[k++] = left[i++];
	}

	// Copy remaining elements from right subarray, if any
	while (j < rightSize) {
		arr[k++] = right[j++];
	}
}

void mergeSort(int arr[], int size) {
	if (size <= 1) {
		return; // Base case: already sorted or empty array
	}

	int mid = size / 2;
	int left[mid];
	int right[size - mid];

	// Split array into left and right subarrays
	for (int i = 0; i < mid; ++i) {
		left[i] = arr[i];
	}
	for (int i = mid; i < size; ++i) {
		right[i - mid] = arr[i];
	}

	// Recursively sort left and right subarrays
	mergeSort(left, mid);
	mergeSort(right, size - mid);

	// Merge sorted left and right subarrays
	merge(arr, left, mid, right, size - mid);
}
//Quicksort
int partition(int arr[], int low, int high) {
	int pivot = arr[low]; // Choose first element as pivot
	int i = low + 1; // Index for elements less than pivot

	for (int j = low + 1; j <= high; ++j) {
		if (arr[j] < pivot) {
			// Swap elements that are less than pivot
			swap(arr[i], arr[j]);
			++i;
		}
	}

	// Move pivot to its correct position
	swap(arr[low], arr[i - 1]);

	return i - 1; // Return index of pivot
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivotIndex = partition(arr, low, high); // Partition the array

		// Recursively sort the subarrays before and after the pivot
		quickSort(arr, low, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, high);
	}
}
//Heapsort
void max_heapify(int *arr, int i, int n) { //Maintains the max heap property
	int rc = (2 * i) + 2;
	int lc = (2 * i) + 1;
	int largest = i;
	if (lc<n && arr[lc]>arr[largest]) largest = lc; //If lc is greater than largest, then the largest element is now lc
	if (rc<n && arr[rc]>arr[largest]) largest = rc; //If rc is greater than largest, then the largest element is now rc
	if (largest != i) {  //If the largest element is not its original element, swap it with the new largest element
		swap(&arr[i], &arr[largest]);
		max_heapify(arr, largest, n); //Recursively call max_heapify() down the rest of the tree.
	}
}
void buildMaxHeap(int *arr, int n) { //Heapifies entire list
	int startindx = (n / 2) - 1; //Start with the half of the list.
	for (int i = startindx; i >= 0; i--) { //Loop from half the list to the beginning of the list
		max_heapify(arr, i, n); //Call max_heapify() on each element
	}
}
void HeapSort(int *arr, int n) { //Prints the array in ascending order
	buildMaxHeap(arr, n); //Calls buildMaxHeap to the unsorted array
	for (int i = n - 1; i >= 0; i--) { //Loop through the whole array
		swap(arr[0], arr[i]); //Swap the max element with the current index
		max_heapify(arr, 0, i); //Rebuild max heap, the heap size is now one less
	}
}
//Counting Sort
void countSort(int *arr, int n, int exp){
	int output[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
//Radix Sort
void radixSort(int *arr, int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);
	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
