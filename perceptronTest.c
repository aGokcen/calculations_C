/*
Multilayer Perceptron
*/
#include<stdio.h>
#include<math.h>

double sigmoid(double x)
{
	return 1/(1+exp(-1*x));
}
double learlingrate = 0.05;
int main()
{
	double x[12][4] = {{1,-1,1,1},{1,-2,1,1},{1,-3,1,1},{2,-1,1,1},
	{-1,4,1,2},{-3,6,1,2},{-1,6,1,2},{1,6,1,2},{4,3,1,3},{4,7,1,3},{5,6,1,3},{6,5,1,3}};
	// dimension is two, how many hidden units? 2*2-1 = 3 hidden units
	double v[4][3]={{0.01, 0.04, 0.05},{0.02, 0.1, 0.05},{0.03,0.04,0.1},{0.05,0.03,0.04}};
	double w[3][4]={0.01, 0.04, 0.05,0.02, 0.1, 0.05,0.03,0.04,0.1,0.05,0.03,0.04};
	double deltaV[4][3]; // Change V
	double deltaW[3][4]; // Change W
	double z[4];
	double y[3];
	int i=0;
	double r[3];
	for(i=0; i<12; i++)
	{
		z[0] = x[i][0]*v[0][0]+x[i][1]*v[0][1]+x[i][2]*v[0][2];
		z[0] = sigmoid(z[0]);
		z[1] = x[i][0]*v[1][0]+x[i][1]*v[1][1]+x[i][2]*v[1][2];
		z[1] = sigmoid(z[1]);
		z[2] = x[i][0]*v[2][0]+x[i][1]*v[2][1]+x[i][2]*v[2][2];
		z[2] = sigmoid(z[2]);
		z[3] = 1.0;
		if(x[i][3]==1)
		{
			r[0] = 1; r[1] = 0; r[2] = 0;
		}
		else if(x[i][3]==2)
		{
			r[0] = 0; r[1] = 1; r[2] = 0;
		}
		else
		{
			r[0] = 0; r[1] = 0; r[2] = 1;
		}
		y[0] = z[0]*w[0][0]+z[1]*w[0][1]*z[2]*w[0][2]*z[3]*w[0][3];
		y[1] = z[0]*w[1][0]+z[1]*w[1][1]*z[2]*w[1][2]*z[3]*w[1][3];
		y[2] = z[0]*w[2][0]+z[1]*w[2][1]*z[2]*w[2][2]*z[3]*w[2][3];
		deltaW[0][0] = z[0]*(r[0]-y[0])*learlingrate;
		deltaW[0][1] = z[1]*(r[0]-y[0])*learlingrate;
		deltaW[0][2] = z[2]*(r[0]-y[0])*learlingrate;
		deltaW[0][3] = z[3]*(r[0]-y[0])*learlingrate;

		deltaW[1][0] = z[0]*(r[1]-y[1])*learlingrate;
		deltaW[1][1] = z[1]*(r[1]-y[1])*learlingrate;
		deltaW[1][2] = z[2]*(r[1]-y[1])*learlingrate;
		deltaW[1][3] = z[3]*(r[1]-y[1])*learlingrate;

		deltaW[2][0] = z[0]*(r[2]-y[2])*learlingrate;
		deltaW[2][1] = z[1]*(r[2]-y[2])*learlingrate;
		deltaW[2][2] = z[2]*(r[2]-y[2])*learlingrate;
		deltaW[2][3] = z[3]*(r[2]-y[2])*learlingrate;
		
		deltaV[0][0] = learlingrate*((r[0]-y[0]*w[0][0])+(r[1]-y[1]*w[1][0])+(r[2]-y[2]*w[2][0]))*z[0]*(1-z[0])*x[i][0];
		deltaV[0][1] = learlingrate*((r[0]-y[0]*w[0][0])+(r[1]-y[1]*w[1][0])+(r[2]-y[2]*w[2][0]))*z[0]*(1-z[0])*x[i][1];
		deltaV[0][2] = learlingrate*((r[0]-y[0]*w[0][0])+(r[1]-y[1]*w[1][0])+(r[2]-y[2]*w[2][0]))*z[0]*(1-z[0])*x[i][2];
		
		deltaV[1][0] = learlingrate*((r[0]-y[0]*w[0][1])+(r[1]-y[1]*w[1][1])+(r[2]-y[2]*w[2][1]))*z[1]*(1-z[1])*x[i][0];
		deltaV[1][1] = learlingrate*((r[0]-y[0]*w[0][1])+(r[1]-y[1]*w[1][1])+(r[2]-y[2]*w[2][1]))*z[1]*(1-z[1])*x[i][1];
		deltaV[1][2] = learlingrate*((r[0]-y[0]*w[0][1])+(r[1]-y[1]*w[1][1])+(r[2]-y[2]*w[2][1]))*z[1]*(1-z[1])*x[i][2];
		
		deltaV[2][0] = learlingrate*((r[0]-y[0]*w[0][2])+(r[1]-y[1]*w[1][2])+(r[2]-y[2]*w[2][2]))*z[2]*(1-z[2])*x[i][0];
		deltaV[2][1] = learlingrate*((r[0]-y[0]*w[0][2])+(r[1]-y[1]*w[1][2])+(r[2]-y[2]*w[2][2]))*z[2]*(1-z[2])*x[i][1];
		deltaV[2][2] = learlingrate*((r[0]-y[0]*w[0][2])+(r[1]-y[1]*w[1][2])+(r[2]-y[2]*w[2][2]))*z[2]*(1-z[2])*x[i][2];

		deltaV[3][0] = learlingrate*((r[0]-y[0]*w[0][3])+(r[1]-y[1]*w[1][3])+(r[2]-y[2]*w[2][3]))*z[2]*(1-z[3])*x[i][0];
		deltaV[3][1] = learlingrate*((r[0]-y[0]*w[0][3])+(r[1]-y[1]*w[1][3])+(r[2]-y[2]*w[2][3]))*z[2]*(1-z[3])*x[i][1];
		deltaV[3][2] = learlingrate*((r[0]-y[0]*w[0][3])+(r[1]-y[1]*w[1][3])+(r[2]-y[2]*w[2][3]))*z[2]*(1-z[3])*x[i][2];

	}
	return 0;
}
