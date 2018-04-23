#include <stdio.h>
#include <stdbool.h>

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
  int i, j, arraySize, ind23, ind31;
  bool flag = false;
  printf("What would you like the size of the array to be? ");
  scanf("%d", &arraySize);
  int array[arraySize];

  for (i=0; i<arraySize; i++) {
    int element;
    printf("Enter element %d: ", i);
    scanf("%d", &element);
    array[i] = element;
  }

  for (i = 0; i < arraySize; i++) {
    if (array[i] == 23) {
      ind23 = i;
      break;
    }
    for (j= ind23; j < arraySize; j++) {
      if (array[j] == 31) {
	ind31 = j;
      }
    }
    if (ind23 < ind31) {
      flag = true;
    }
    else {
      flag = false;
    }
  }
  if (flag == true) {
    printf("YES\n");
  }
  else {
    printf("NO\n");
  }
}
