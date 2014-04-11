/*GDC CALCULATOR             */
/*Alpaslan GOKCEN 11.04.2014 */
#include<stdio.h>
int main()
{
	int n1,n2,min,i,_gdc=1;
	printf("Enter first Number:");
	scanf("%d",&n1);
	printf("Enter second Number:");
	scanf("%d",&n2);
	min=n1<n2?n1:n2;
	for(i=2;i<=min; i++)
	{
		if(n1%i==0 && n2%i==0)
		{
			while (n1%i==0 && n2%i==0)
			{
				_gdc*=i;
				n1/=i;
				n2/=i;
			}
		}
	}
	printf("GDC:%d\n",_gdc);
	return 0;
}
