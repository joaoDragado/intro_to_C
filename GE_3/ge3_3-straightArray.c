#include <stdio.h>


/* συνάρτηση dyn,δέχεται ως ορίσματα μια διπλή x και μια ακέραια k ; επιστρέφει το x^k. */
double dyn(double x,int k)
{
	int i;	
	double z =1;
	for (i = 0; i < k; i++) z *=x;
	return z;
}

/*συνάρτηση p, δέχεται ως ορίσματα δείκτη s σε πίνακα που περιέχει συντελεστές πολυωνύμου, διπλή x, και ακέραια n που αντιστοιχεί στο βαθμό πολυωνύμου; επιστρέφει την τιμή του πολυωνύμου συμβατικά*/
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
/*συνάρτηση h, δέχεται ως ορίσματα δείκτη s σε πίνακα που περιέχει συντελεστές πολυωνύμου, διπλή x, και ακέραια n που αντιστοιχεί στο βαθμό πολυωνύμου; επιστρέφει την τιμή του πολυωνύμου κατά Horner */
double h(double *s, double x, int n)
{
	int i;
	double z =s[n];			// initialize with highest degree coefficient
	for (i = n; i >0 ; i--)	//reverse iteration;
	{
		z= z*x + s[i-1] ;	 
	}
		return z;
}


int main(void)
{
	double c[10], x; // declare coefficient array & variable x  
	int i,b;				// declare polynomial degree
	
	printf("Enter the polynomial degree: ");
	scanf("%d",&b);
	while (b<0 || b>10)	//αμυντικός προγραμματισμός
		{
		printf("Degree must be positive and less than 10. Try again : ");
		scanf("%d",&b);
		}
	
	printf("Enter the value of the constant term: ");
	scanf("%lf",&c[0]);
	for (i = 1; i <=b ; i++)
	{
		printf("Enter the value of the %d degree coefficient: ", i);
		scanf("%lf",&c[i]);
	}
	
	printf("Enter the value of variable x: ");
	scanf("%lf",&x);
	
	printf("The value of the polynomial using the conventional method is : %.3lf\n",p(c,x,b));
	printf("The value of the polynomial using the Hohner method is : %.3lf\n",h(c,x,b));

	return (0);
}







 
