#include<stdio.h>
#define SIZE 5
int factor(int);
int powers(int,int);
int multiplay(int,int);
int sum(int [],int);
int max(int arr[],int size);
int avarage(int arr[],int size);
int main()
{
	int arr[SIZE]={1,2,3,4,5};
	printf("%d\n",factor(5));
	printf("%d\n",powers(3,2));
	printf("%d\n",multiplay(3,2));
	printf("%d\n",sum(arr,SIZE-1));
	printf("%d\n",max(arr,SIZE-1));
	printf("%d\n",avarage(arr,SIZE-1));
	getchar();
	getchar();
}
int factor(int n)
{
	if(n==1)
		return 1;
	return n*factor(n-1);
}

int powers(int power,int x)
{
	if(power==1)
		return x;
	return x*powers(power-1,x);
}

int multiplay(int a,int b)
{
	if(b==1)
		return a;
	return a+multiplay(a,b-1);
}
int sum(int arr[],int size)
{
	if(size==0)
		return arr[size];
	return arr[size]+sum(arr,size-1);
}
int max(int arr[],int size)
{
	if(size==0)
		return arr[size];
	else if(arr[size]>max(arr,size-1))
		return arr[size];
	else
		return max(arr,size-1);
}
int avarage(int arr[],int size)
{
	if(size==0)
		return arr[size];
	return (size-1)*(arr[size]+avarage(arr,size-1))/(size);
}
