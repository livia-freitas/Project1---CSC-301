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
 */

#include "project1.hpp"

using namespace std;

/*
 * selectionSort
 */
void selectionSort(vector<double> &arrayToSort) {
    return;
}

/*
 * insertionSort
 * 
 * This function sorts the input vector using the insertion sort algorithm.
 * It starts by iterating through the vector, placing each element in its 
 * correct position relative to the already sorted section.
 *
 * @param arrayToSort - The vector of doubles to be sorted in ascending order.
 * @return void - The function modifies the vector in place.
 */
void insertionSort(vector<double> &arrayToSort) {
    int n = arrayToSort.size(); // initialize

    // Iterate through the array starting from the second element.
    for (int i = 1; i < n; i++) {
        double key = arrayToSort[i]; // The current element to be inserted.
        int m = i - 1;

        // Shift elements of the sorted portion of the array to the right
        // until the correct position for the key is found.
        while (m >= 0 && arrayToSort[m] > key) {
            arrayToSort[m + 1] = arrayToSort[m];
            m--; // Move to the previous element.
        }

        // Insert the key at the correct position.
        arrayToSort[m + 1] = key;
    }
}


/*
 * bubbleSort
 */
void bubbleSort(vector<double> &arrayToSort) {
    return;
}

/*
 * mergeSort
 */
void mergeSort(vector<double> &arrayToSort) {
    return;
}

/*
 * quickSortHelper
 * 
 * Note that i is inclusive (i.e., is the first element of subarray).
 * Note that j is not inclusive (i.e., off the end of the subarray).
 * 
 */
void quickSortHelper(vector<double> &arrayToSort, int i, int j) {
    return;
}

/*
 * quickSort
 */
void quickSort(vector<double> &arrayToSort) {
    quickSortHelper(arrayToSort, 0, arrayToSort.size());
    return;
}
