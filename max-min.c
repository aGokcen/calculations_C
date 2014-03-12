/* Alpaslan Gökcen - Maximum and Minumum analyzer for 3 Number */
#include<stdio.h>
int main()
{
	int number1,number2,number3;
	printf("Enter first number: "); scanf("%d",&number1);
	printf("Enter second number: "); scanf("%d",&number2);
	printf("Enter third number: "); scanf("%d",&number3);
	max_min(number1,number2,number3);
	return 0;
}
int max_min(int a,int b,int c)/*a is Number 1,b is Number 2, c is number 3 */
{
	int temp;
	 if( a>b )
	 {
		 temp = a;
		 a = b;
		 b = temp;}
	 if( b>c ){
		 temp = b;
		 b = c;
		 c = temp;
	 }
	 if( a>b )
	 {
		 temp = a;
		 a = b;
		 b = temp;
	 }
	 printf("%d < %d < %d \n",a,b,c);
	 return 0 ;
}
