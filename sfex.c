#include <stdio.h>

int main() {
  int i;
  int n;
  int j;
  int A [20] = {[0 ... 19] = 5};

  printf("Type in a number: ");
  scanf("%d", &n);

  for (i=1; i<=n; i++)      // explore the numbers
    {
      int f=0;              // flag
      for (j=0; j<n-1; j++) // explore the array indices
	{
	  if (A[j]==i)      // number found
	    {
	      f=1;          // set flag to 1
	      break;        // break out of indices exploration loop
	    }
	}
      if (f==0) {           // number not found
	printf("Number %d is missing\n", i);
      }
    }
}
