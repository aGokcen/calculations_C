/* Alpaslan GOKCEN- Simple Calculator */
#include<stdio.h>
#define PI 3.14
int main()
{
	char character=' ';
	float radius,width,height=0.0f;
	printf("\nChoose one of Calculation then type enter! \n");
	printf("1-) Circle area calcutor \n");
	printf("2-) Square area calcutor \n");
	scanf("%c",&character);
	switch (character)
	{
	case '1':
		
			printf("Welcome to circle area calculator,please enter radius: ");
			scanf("%f",&radius);
			printf("Area of circle is :%.2f \n",radius*radius*PI);
			break;
	case '2':
		
			printf("Welcome to square area calculator,please enter width,h! \n1-)Enter width: ");
			scanf("%f",&width);
			printf("2-)Enter height :");
			scanf("%f",&height);
			printf("Area of square is :%.2f \n",width*height);
			break;
	default:
		break;
	}
	return 0;
}
