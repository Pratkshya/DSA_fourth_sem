//WAP to compute e^x = 1 + x + x^2/2! + ..........x^n/n!, where n represents number of  terms. The program should read the value of n from the user.

#include <stdio.h>
#include <math.h>
void main()
{
  float x,fact,sum = 0, powValue;
  int n,i,j;
  printf("Enter the value of x and n: ");
  scanf("%f %d", &x, &n);
  for(i = 0; i<=n; i++)
  {
      powValue = pow(x,i);
      fact=1;
      for(j = 1; j<=i; j++)
      {
         fact = j*fact;
      }
      sum = sum + powValue/fact;
  }
  printf("\nThe sum of the series is: %f",sum);
}