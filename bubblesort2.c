#include <stdio.h>
#include <stdbool.h>

// Bubble sort: simplest algorithm to sort 
// change elements around, let bubble settle to top of array
void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
 
// Bubble sort function
void bubbleSort(int arr[], int n)
{
  int i, j;
  for (i=0; i<n-1; i++)     
    for (j=0; j<n-i-1; j++) 
      if (arr[j] > arr[j+1]) // compare neighbouring elements
	swap(&arr[j], &arr[j+1]); // swap the elements if necessary
}
 
// Function to print an array
void printArray(int arr[], int size)
{
  for (int i=0; i<size; i++)
    printf("%d ", arr[i]);
}
 
// Driver program to test above functions
int main()
{
  int arr[] = {2, 1, 4, 5, 6, 7, 9, 8}; // put array in here
  int n = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);

  int revarr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; //put array in here                      
  int revsize = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(revarr, revsize);
  printf("Sorted reverse array: \n");
  printArray(revarr, revsize);
  return 0;
}
