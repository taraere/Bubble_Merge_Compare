#include <stdio.h>
 
int main()
{
  int array[100], n, c, d, swap; 

  printf("How many integer elements are there?\n");
  scanf("%d", &n);
  //e.g. 10 

  printf("Enter the %d integer elements\n", n);
  /* e.g. 8 2 9 3 0 4 5 9 1 7
     0 9 8 7 6 5 4 3 2 1
     0 9 1 2 3 4 5 6 7 8 
     1 8 2 3 4 9 5 7 6 0 */
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);
 
  for (c = 0 ; c < ( n - 1 ); c++)
    {
      for (d = 0 ; d < n - c - 1; d++)
	{
	  if (array[d] > array[d+1])
	    {
	      swap = array[d];
	      array[d] = array[d+1];
	      array[d+1] = swap;
	    }
	}
    }
 
  printf("The list sorted in increasing order is:\n");
 
  for ( c = 0 ; c < n ; c++ )
    printf("%d\n", array[c]);
 
  return 0;
}
