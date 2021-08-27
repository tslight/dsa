#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    unsigned long number, i, j;
    bool multiple = false;

    if (argc<=1) {
	printf("Enter Number: ");
	scanf("%lu", &number);
    } else {
	number = strtoul(argv[1], argv, 10);
    }

    while (i>=number) {

	for (j=1; j<=number; j++) {

	    if (i%j == 0) {
		multiple=true;
	    } else {
		multiple=false;
		break;
	    }
	}

	if (multiple == true) {
	    printf("Multiple found at %lu\n" ,i);
	    break;
	}
	i++;
    }
}
