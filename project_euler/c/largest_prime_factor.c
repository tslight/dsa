#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    unsigned long last_factor;
    unsigned long factor;
    unsigned long number;
/* bool prime; */

    if (argc<=1) {
	printf("Enter Number: ");
	scanf("%lu", &number);
    } else {
	number=strtoul(argv[1], argv, 10);
    }

    if (number%2 == 0) {
	number=number/2;
	last_factor=2;
	while (number%2 == 0) {
	    number=number/2;
	}
    } else {
	last_factor=1;
    }

    factor=3;
    while (number>1) {
	if (number%factor == 0) {
	    number=number/factor;
	    last_factor=factor;
	    while (number%factor == 0) {
		number=number/factor;
	    }
	}
	factor=factor+2;
    }
    printf("%lu " ,last_factor);

    /* for (i=2; i<n; i++) { */
    /*	prime=true; */
    /*	if (n%i == 0) { */
    /*	    for (j=2; j<i/2; j++) { */
    /*		if (i%j == 0) { */
    /*		    prime=false; */
    /*		    break; */
    /*		} */
    /*	    } */
    /*	    if (prime) { */
    /*		printf("%lu, " ,i); */
    /*	    } */
    /*	} */
    /* } */
    printf("\n");
}
