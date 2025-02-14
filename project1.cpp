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
 */
void selectionSort(vector<double> &arrayToSort) {
    return;
}

/*
<<<<<<< Updated upstream
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
=======
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
>>>>>>> Stashed changes
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
