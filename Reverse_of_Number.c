/*This program can find Reverse of Number */
/*Alpaslan Gökcen  12.04.2014             */
#include<stdio.h>
int main()
{
	int counter=0,number,_number,i,d=1;
	printf("Enter Number:");
	scanf("%d",&number);
	_number=number;
	while (_number)/*Number Lenghth counter */
	{
		_number/=10;
		counter++;
	}
	for(i=1;i<counter;i++)/*This loop for calculating 10's Power */
	{
		d*=10;
	}
	
	while (d)/*Reverse Loop */
	{
		printf("%d",number/d);
		number%=d;
		d/=10;
	}
	return 0;
}
