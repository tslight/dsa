#include <stdio.h>

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
    int element = array[i];
    int j = i;
    while (j > 0 && array[j-1] > element) {
      array[j] = array[j-1];
      j = j - 1;
    }
    array[j] = element;
    printf("Array after iteration %d = ", i);
    printArray(array, arraySize);
  }

  printf("Array after sorting = ");
  printArray(array, arraySize);
}
