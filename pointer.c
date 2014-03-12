/* Alpaslan Gökcen - Pointer test */
#include<stdio.h>
int main()
{
	int *pointer,var;
	pointer=&var;
	var=123;
	printf("%d \n",var);
	printf("%d \n",&var);
	printf("%d \n",*pointer);
	printf("%d \n",pointer);
}
