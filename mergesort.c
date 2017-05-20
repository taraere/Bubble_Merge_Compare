#include<stdlib.h>
#include<stdio.h>

// l = left index, r = right index
void merge(int arr[], int l, int m, int r)
{
  // declare local variables
  int i, j, k;
  // middle minus left hand index plus one
  int n1 = m - l + 1;
  // right hand index minus middle
  int n2 = r - m;

  // create temporary arrays
  int L[n1], R[n2];

  /* copy data to temporary arrays L[] and R[] 
  (first/left list and second/right list) */
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];

  // initialise index. 
  // Compare subarrays & merge temporary arrays into array l..r as arr[l..r]
  i = 0; // first subarray 
  j = 0; // second subarray 
  k = l; // merged subarray 

  // pass through elements in order
  while (i < n1 && j < n2)
    {
      if (L[i] <= R[j])
	{
	  arr[k] = L[i];
	  i++;
	}
      else
	{
	  arr[k] = R[j];
	  j++;
	}
      k++;
    }

  // add remaining elements of L[] and then of R[]
  while (i < n1)
    {
      arr[k] = L[i];
      i++;
      k++;
    }

  while (j < n2)
    {
      arr[k] = R[j];
      j++;
      k++;
    }
}

/* take arguments array, left, and right index. Initialize these */
void mergeSort(int arr[], int p, int r)
{
  if (p < r)
    {
      // m = (l+r)/2 but to avoid overflow, m = (l+(r-1))/2
      int m = p+(r-p)/2;
      // sort left, then right half
      mergeSort(arr, p, m);
      mergeSort(arr, m+1, r);
      merge(arr, p, m, r);
    }
}

// to test the functions, print input and output

void printArray(int A[], int size)
{
  int i;
  // for lowest and highest index, and incrementation, print the array
  for (i=0; i < size; i++)
    printf("%i ", A[i]);
  // printf("\n");
}

/* Test the functions */
int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr)/sizeof(arr[0]);

  printf("Input \n");
  printArray(arr, arr_size);

  mergeSort(arr, 0, arr_size - 1);

  printf("\nOutput (sorted input): \n");
  printArray(arr, arr_size);
  
  // odd example
  int oddArr[] = {12, 11, 13, 5, 6, 7, 4};
  int oddArr_size = sizeof(oddArr)/sizeof(oddArr[0]);

  printf("\nOdd array: \n");
  printArray(oddArr, oddArr_size);
  mergeSort(oddArr, 0, oddArr_size - 1);

  printf("\nOdd output: \n");
  printArray(oddArr, oddArr_size);

  return 0;
}
