#include <stdio.h>

int factorial (int n)
{
  if (n == 1) {
    return 1;
  }
  else {
    return n*factorial(n-1);
  }
}

int main()
{
  int n;
  int i;
  printf("What number do you want the factorial of? ");
  scanf("%d", &n);
  i = factorial(n);
  printf("The factorial of %d is %d\n",n,i);
}
