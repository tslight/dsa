#include <stdio.h>

int main() {
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
  printf("Array = ");
  for (i=0; i<arraySize; i++) {
    if (i == arraySize-1) {
      printf("%d\n", array[i]);
    }
    else {
      printf("%d, ", array[i]);
    }
  }
}
