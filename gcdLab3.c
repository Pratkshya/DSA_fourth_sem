//GCD using recursion
#include <stdio.h>
int gcd (int a, int b)
{
  if(b == 0)
  {
    return a;
  }
  else
  {
    return gcd(b, a%b);
  }
}
int main()
{
  int x,y;
  printf("Enter any two numbers: ");
  scanf("%d %d", &x,&y);
  printf("The answer is: %d", gcd(x,y));
  return 0;
}
