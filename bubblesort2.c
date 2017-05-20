#include <stdio.h>
#include <stdbool.h>

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
 
// Function to implement bubble sort
void bubbleSort(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n-1; i++)      
 
    // Last i elements are already in place   
    for (j = 0; j < n-i-1; j++) 
      if (arr[j] > arr[j+1]) // compare adjacent elements
	swap(&arr[j], &arr[j+1]); // swap the elements if need be
}
 
// Function to print an array
void printArray(int arr[], int size)
{
  for (int i=0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
 
// Driver program to test above functions
int main()
{
  int arr[] = {20, 303, 29, 3, 39, 1}; //put array in here
  int n = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}
