#include <stdio.h>
#include <string.h>

double dyn(double x,int k)
{
	int i;	
	double z =1;
	for (i = 0; i < k; i++) z *=x;
	return z;
}

double p(double *s, double x, int n)
{
	int i;
	double z =0;
	for (i = 0; i <=n ; i++)
	{
		z+= s[i]*dyn(x,i);
	}
		return z;
}

double h(double *s, double x, int n)
{
	int i;
	double z =s[n];
	for (i = n; i >0 ; i--)
	{
		z= z*x + s[i-1] ;
	}
		return z;
}

int main(void)
{
	double s[]={-2.0,4.0,-3.0,2.0};
	printf("%.2lf\n", h(s,2,3));
	return (0);
}







 
