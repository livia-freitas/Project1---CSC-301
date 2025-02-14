/*
 * CSC-301
 * project1.cpp
 * Spring 2025
 *
 * Project 1 - Sorting
 *
 * Partner 1: Princess Alexander
 * Partner 2: Livia Stein Freitas
 * Date: February 10th, 2025
 * Acknowledgements: We consulted the Introduction to Algorithms book
 * by Cormen, Leiserson, River, and Stein. We also consulted
 * Prof. Eric Autry's slides.
 */

#include "project1.hpp"
//#include <matplotlib>
//#include <lapack>
using namespace std;

/*
 * selectionSort
 *
 * Implements the Selection Sort algorithm.
 * It repeatedly finds the minimum element and moves it to the sorted part.
 *
 * in: arrayToSort - vector of doubles.
 * out: nothing (array is sorted in place).
 */
void selectionSort(vector<double> &arrayToSort) {
    int n = arrayToSort.size();
    for (int i = 0; i < n - 1; i++) { // Iterate through array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) { // Find min element
            if (arrayToSort[j] < arrayToSort[minIndex]) {
                minIndex = j;
            }
        }
        swap(arrayToSort[i], arrayToSort[minIndex]); // Swap min with first unsorted
    }
    return;
}

/*
 * insertionSort 
 *
 * insertionSort sorts an array by separating the array into a sorted
 * component and an unsorted one. Each iteration, 
 * it moves one elements from the unsorted subarray to sorted side.
 * 
 * in: arrayToSort - doubles array.
 * out: nothing.
 * 
 */
void insertionSort(vector<double> &arrayToSort) {
    int n = arrayToSort.size();
    for (int pos = 0; pos < n; pos++){
        double rabbit = arrayToSort[pos]; //rabbit: element to be sorted
        int i = pos - 1;
        while (i >= 0 and arrayToSort[i] > rabbit){
            arrayToSort[i + 1] = arrayToSort[i]; //swap elements if in wrong order
            i = i - 1;
        }
        arrayToSort[i + 1] = rabbit; //put rabbit in correct position
    }
    return;
}


/*
 * bubbleSort
 *
 * bubbleSort sorts an array by iteratively comparing adjacent elements and
 * swapping them. This repeats until there are no more swaps. 
 * It returns nothing, only changes the array.
 *
 * arrayToSort: an array of unsorted doubles.
 */
void bubbleSort(vector<double> &arrayToSort) {
    // Say n is the size of the array. We will at most k times.
    // According to our invariant from class, the kth largest elements
    // should be sorted at the kth iteration. 
    int n = arrayToSort.size();
    for (int k = 0; k < n; k++){
        bool swapped = false;
        for(int i = 0; i + 1 < n; i++){
            if(arrayToSort[i] > arrayToSort[i + 1]){ //how do you know if there are no swaps?
                // could make this a classic swap helper
                double temp = arrayToSort[i];
                arrayToSort[i] = arrayToSort[i + 1];
                arrayToSort[i + 1] = temp;
                swapped = true;
            } //boolean variable for keeping track of swaps!!! 
        }
        if (swapped == false){
            return;
        }
    }
}

/*
 * merge
 *
 * Merges two sorted subarrays into one sorted array.
 *
 * in: arrayToSort - vector of doubles.
 *     left - starting index of left subarray.
 *     mid - ending index of left subarray.
 *     right - ending index of right subarray.
 * out: nothing (array is merged in place).
 */
void merge(vector<double> &arrayToSort, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    vector<double> leftArr(leftSize);
    vector<double> rightArr(rightSize);
    
    // Copy data to temp arrays
    for (int i = 0; i < leftSize; i++) leftArr[i] = arrayToSort[left + i];
    for (int j = 0; j < rightSize; j++) rightArr[j] = arrayToSort[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    // Merge back to original array
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arrayToSort[k++] = leftArr[i++];
        } else {
            arrayToSort[k++] = rightArr[j++];
        }
    }
    
    // Copy remaining elements if any
    while (i < leftSize) arrayToSort[k++] = leftArr[i++];
    while (j < rightSize) arrayToSort[k++] = rightArr[j++];
}

/*
 * mergeSortHelper
 *
 * Recursively sorts an array using Merge Sort.
 *
 * in: arrayToSort - vector of doubles.
 *     left - starting index of subarray.
 *     right - ending index of subarray.
 * out: nothing (array is sorted in place).
 */
void mergeSortHelper(vector<double> &arrayToSort, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Avoids overflow
        mergeSortHelper(arrayToSort, left, mid);
        mergeSortHelper(arrayToSort, mid + 1, right);
        merge(arrayToSort, left, mid, right);
    }
}

/*
 * mergeSort
 *
 * Sorts an array using Merge Sort.
 *
 * in: arrayToSort - vector of doubles.
 * out: nothing (array is sorted in place).
 */
void mergeSort(vector<double> &arrayToSort) {
    mergeSortHelper(arrayToSort, 0, arrayToSort.size() - 1);
}


/*
 * partition
 *
 * Partitions the array for Quick Sort.
 *
 * in: arrayToSort - vector of doubles.
 *     low - starting index.
 *     high - ending index.
 * out: partition index.
 */
int partition(vector<double> &arrayToSort, int low, int high) {
    double pivot = arrayToSort[high]; // Pivot element
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arrayToSort[j] <= pivot) { // Swap if element is smaller than pivot
            swap(arrayToSort[++i], arrayToSort[j]);
        }
    }
    swap(arrayToSort[i + 1], arrayToSort[high]);
    return i + 1;
}



/*
 * quickSortHelper
 *
 * Recursively sorts an array using Quick Sort.
 *
 * in: arrayToSort - vector of doubles.
 *     i - starting index (inclusive).
 *     j - ending index (exclusive).
 * out: nothing (array is sorted in place).
 */
void quickSortHelper(vector<double> &arrayToSort, int i, int j) {
    if (i < j - 1) { // Ensures at least 2 elements in range
        int pivotIndex = partition(arrayToSort, i, j - 1);
        quickSortHelper(arrayToSort, i, pivotIndex); // Sort left partition
        quickSortHelper(arrayToSort, pivotIndex + 1, j); // Sort right partition
    }
}

/*
 * quickSort
 *
 * Sorts an array using Quick Sort.
 *
 * in: arrayToSort - vector of doubles.
 * out: nothing (array is sorted in place).
 */
void quickSort(vector<double> &arrayToSort) {
    quickSortHelper(arrayToSort, 0, arrayToSort.size());
}
