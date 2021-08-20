#include <stdio.h>

int main() {
  int i;
  int n;
  int A [10] = {1, 2, 3, 4, 5, 6, 7, 9, 10};

  printf("Type in a number: ");
  scanf("%d", &n);

  int s1 = n*(n+1)/2; // sum of numbers from 1 to n

  int s2 = 0; // sum of array
  for (i=0; i<n; i++) {
    s2=s2+A[i];
  }

  int s3 = s1 - s2;
  printf("s1 = %d \n", s1);
  printf("s2 = %d \n", s2);
  printf("Number %d is missing\n", s3);
}
