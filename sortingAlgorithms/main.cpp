#include <iostream>
#include <math.h>
#include <chrono>
#include <iomanip>
using namespace std;

/**
 * Method: Swap
 *    Swap the two number.
 *
 * @param   *element1 - The pointer to number be swapped
 *          *element2 - The pointer to number be swapped
 *
 * @return  nothing
 */
void swap(int *element1, int *element2)
{
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

/**
 * Method: Swap
 *    Function to sort an array using selection sort.
 *
 * @param   arr[] - The number to be swapped
 *          size - Size of the array
 *
 * @return  nothing
 */
void selectionSort(int arr[], int size)
{
    int i, j, min;
    for (i = 0; i < size-1; i++)            // One by one move boundary of unsorted subarray
    {
        min = i;                            // Find the minimum element in unsorted array
        for (j = i+1; j < size; j++){
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);           // Swap the found minimum element with the first element
    }
}

/**
 * Method: insertionSort
 *    Function to sort an array using insertion sort.
 *
 * @param   arr[] - Array of integers
 *          size - Size of the array
 *
 * @return  nothing
 */
void insertionSort(int arr[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key)      //Elements that are greater than key
        {
            arr[j+1] = arr[j];              //Move elements to one position ahead of their current position
            j = j-1;
        }
        arr[j+1] = key;
    }
}

/**
 * Method: bubbleSort
 *    A function to implement bubble sort.
 *
 * @param   arr[] - Array of integers
 *          size - Size of the array
 *
 * @return  nothing
 */
void bubbleSort(int arr[], int size)
{
    
    int i, j;
    for (i = 0; i < size-1; i++){
        for (j = 0; j < size-i-1; j++){      // Last i elements are already in place
            if (arr[j] > arr[j+1]){
                
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/**
 * Method: printArray
 *    A utility function ot print an array of size size.
 *
 * @param   arr[] - Array of integers
 *          size - Size of the array
 *
 * @return  nothing
 */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << " - " << arr[i]<< endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 34, 68, 1, 89, 77, 184, 212, 111, 63, 15, 5, 90, 178, 55};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Sorted array using Selection Sort:\n";
    selectionSort(arr, size);
    printArray(arr, size);
    cout << endl;
    cout << "Sorted array using Insertion Sort:\n";
    insertionSort(arr, size);
    printArray(arr, size);
    cout << endl;
    cout << "Sorted array using Bubble Sort:\n";
    bubbleSort(arr, size);
    printArray(arr, size);
    cout << endl;
    return 0;
}

