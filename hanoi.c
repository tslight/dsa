#include <stdio.h>

void towerOfHanoi(int n, char fromrod, char torod, char auxrod)
{
  if (n == 1)
    {
      printf("Move disk 1 from rod %c to rod %c\n", fromrod, torod);
      return;
    }
  towerOfHanoi(n-1, fromrod, auxrod, torod);
  printf("Move disk %d from rod %c to rod %c\n", n, fromrod, torod);
  towerOfHanoi(n-1, auxrod, torod, fromrod);
}

int main()
{
  int n;
  printf("How many disks are there to move? ");
  scanf("%d", &n);
  towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
  return 0;
}
