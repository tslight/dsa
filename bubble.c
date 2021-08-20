/* Bubble sort code */

#include <stdio.h>
#include <stdbool.h>

void printArray(int array[], int arraySize) {
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

int main() {
    int array[100], n, c, d, swap;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);

    for (c = 0; c < n; c++)
	scanf("%d", &array[c]);

    bool sorted = false;
    int lastUnsorted = n - 1;
    int iterationCount;
    while (!sorted) {
	sorted = true;
	for (c = 0; c < lastUnsorted; c++) {
	    if (array[c] > array[c+1]) /* For decreasing order use < */
	    {
		swap       = array[c];
		array[c]   = array[c+1];
		array[c+1] = swap;
		sorted = false;
	    }
	    printf("Array after iteration %d: ",c);
	    printArray(array,n);
	}
	iterationCount++;
	lastUnsorted--;
    }

    printf("Sorted list in ascending order: ");
    printArray(array,n);
    printf("Iteration count: %d", iterationCount);

    return 0;
}
