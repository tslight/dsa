#include <stdio.h>

int indexSmallest(int i, int array[], int n) {
  int j;
  int minind=i; // set minimum element to first element in array
  for (j=i+1;j<n;j++) {
    if (array[j]<array[minind]) { // is element smallest than adjacent?
      minind=j;
    }
  }
  return minind;
}

printArray(int array[], int arraySize) {
  int i;
  for (i=0; i<arraySize; i++) {
    if (i == arraySize-1) {
      printf("%d\n", array[i]);
    }
    else {
      printf("%d, ", array[i]);
    }
  }
}

main() {
  int i;
  int arraySize;
  printf("What would you like the size of the array to be? ");
  scanf("%d", &arraySize);
  int array[arraySize];

  for (i=0; i<arraySize; i++) {
    int element;
    printf("Enter element %d: ", i);
    scanf("%d", &element);
    array[i] = element;
  }

  printf("Array before sorting = ");
  printArray(array, arraySize);

  for (i=0; i<arraySize; i++) {
    int k = indexSmallest(i, array, arraySize);
    int d = array[i]; // placeholder for current value
    array[i] = array[k]; // swap current value to smallest of remaing elements
    array[k] = d;
    printf("Array after iteration %d = ", i);
    printArray(array, arraySize);
  }

  printf("Array after sorting = ");
  printArray(array, arraySize);
}
