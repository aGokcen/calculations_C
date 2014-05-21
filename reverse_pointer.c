/*21.05.2014 Swap-reverse-pointer-array-Call by Reference */
#include<stdio.h>
#define SIZE 10
void input(int *,int);
void output(int *,int);
void swap(int *,int);
void reverse(int *,int);
int main()
{
	int size,arr[]={1,2,3,4,5,6,7,8,9};
	scanf("%d",&size);
	input(arr,size);
	output(arr,size);
	size = 9;
	swap(arr,size);
	reverse(arr,size);
	output(arr,size);
	scanf("%d");
}
void input (int *parr,int size)
{
	int counter;
	for(counter=0;counter<size;counter++)
	{
		scanf("%d",parr++);
	}
}
void output(int *parr,int size)
{
	int counter;
	for(counter=0;counter<size;counter++)
	{
		printf("%d",*parr++);
	}
}
void swap(int *parr,int size)
{
	int counter;
	for(counter=0;counter<size-1;counter+=2)
	{
		int temp;
		temp=*parr;
		*parr=*(parr+1);
		*(parr+1)=temp;
		parr+=2;
	}
}
void reverse(int *parr,int size)
{
	int i;
	int d;
	for(i=0, d=size-1;i<d; i++,d--)
	{
		int t;
		t=*(parr+i);
		*(parr+i)=*(parr+d);
		*(parr+d)=t;
	}
}
