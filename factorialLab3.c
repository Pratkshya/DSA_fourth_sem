//Factorial using recursion
#include <stdio.h>
int fact(int n)
{
  if (n == 1) //Base case
  {
    return 1;
  }
  else
  {
    return n * fact(n-1);
  }
}
int main()
{
  int n;
  printf("Enter any number: ");
  scanf("%d", &n);
  if(n<0)
  {
    printf("Please enter the non-negative number");
  }
  else if(n==0)
  {
    printf("The factorial of the number %d is not defined", n);
  }
  else
  {
    printf("The factorial of the number %d is: %d", n, fact(n));
  }
  return 0;
}
