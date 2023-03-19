#include<stdio.h>

int main ()
{
   long int sum=0;
   for (long i=1; i<=10000000; i++)
      sum += i;
   printf("The sum of first 100 million positive numbers is %ld\n", sum);
}
