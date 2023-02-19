#include <stdio.h>
#include "header.h"
int main()
{
   int a,b;
   scanf("%d %d",&a,&b);
    printf("the number you enterd is %d and %d",a,b);
   printf("\nthe value is printed");
    printf("\nHello Function is executed");
    add(a,b);
   printf("\nadd Function is executed");
    subtract(a,b);
  printf("\nsubtract function is executed");
   multiplication(a,b);
   printf("\nMultiplication function is executed");
   division(a,b);
  printf("\nDivision function is executed");
   printf("\nThe program is ended");
 }
