#include<stdio.h>
#include<math.h>
void main()
{
	double w[4][2] = {0.2,0.8,0.4,0.4,0.5,0.7,0.9,0.3}; // 4 feautures and 2 cluster
	double gainterm = 0.6;
	double samples[4][4]={1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1};
	double d1 = 0;
	double d2 = 0;
	// begin training(Euclidian distance measure)
	int j=0;
	while(1)
	{
		int i = 0;
		if(j==1000)
			break;
		for(i = 0; i<4; i++)
		{
			d1 = (samples[i][0]-w[0][0])*(samples[i][0]-w[0][0])+(samples[i][1]-w[1][0])*(samples[i][1]-w[1][0])+(samples[i][2]-w[2][0])*(samples[i][2]-w[2][0])+(samples[i][3]-w[3][0])*(samples[i][3]-w[3][0]);
			d2 = (samples[i][0]-w[0][1])*(samples[i][0]-w[0][1])+(samples[i][1]-w[1][1])*(samples[i][1]-w[1][1])+(samples[i][2]-w[2][1])*(samples[i][2]-w[2][1])+(samples[i][3]-w[3][1])*(samples[i][3]-w[3][1]);
			if(d1>d2)
			{
				w[0][1] = w[0][1]+gainterm*(samples[i][0]-w[0][1]);
				w[1][1] = w[1][1]+gainterm*(samples[i][1]-w[1][1]);
				w[2][1] = w[2][1]+gainterm*(samples[i][2]-w[2][1]);
				w[3][1] = w[3][1]+gainterm*(samples[i][3]-w[3][1]);
			}
			else if(d2>d1)
			{
				w[0][0] = w[0][0]+gainterm*(samples[i][0]-w[0][0]);
				w[1][0] = w[1][0]+gainterm*(samples[i][1]-w[1][0]);
				w[2][0] = w[2][0]+gainterm*(samples[i][2]-w[2][0]);
				w[3][0] = w[3][0]+gainterm*(samples[i][3]-w[3][0]);
			}
		}
		gainterm/=2;
		printf("%1f\t%1f\n",w[0][0],w[0][1]);
		printf("%1f\t%1f\n",w[1][0],w[1][1]);
		printf("%1f\t%1f\n",w[2][0],w[2][1]);
		printf("%1f\t%1f\n",w[3][0],w[3][1]);
		printf("************************\n");
		j++;
	}
	scanf("%d",j);

}
