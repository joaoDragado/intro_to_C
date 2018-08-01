#include <stdio.h>

#define EMPLOYEE 4
// No of employees as constant

/*function that accepts annual income as integer and returns amount withheld as annual tax. */
int computeTax(int value) {

	float tax;
	
	if (value<=25000) 
		tax=value*0.22; 
	else if (value<=42000) 
		tax=25000*0.22+(value-25000)*0.32; 
	else 
		tax=25000*0.22+42000*0.32+(value-42000)*0.42; 
	
	return tax;	
}


int main(void)
{
/* declare counter, temp, and arrays holding employee gross  & net incomes*/       
    int i, a, grossInc[EMPLOYEE],netInc[EMPLOYEE] ;

/* User to input annual income for each employee, stored in the grossInc array - def. prog. for negative values */    

	for (i = 0; i < EMPLOYEE; i++)
	{
		printf("Please enter Annual gross income of employee No. %d:\n",i+1);
		scanf("%d",&a);
		while (a<0){
			printf("Negative values are not accepted. Please try again.\n");
			scanf("%d",&a);
		}
		grossInc[i] = a;
	}

/* Prints annual tax withheld from salary of each employee, using the function computeTax */
	
	for (i = 0; i < EMPLOYEE; i++)
	{
	
	printf("Annual Tax amount withheld from employee No. %d is: EUR %d\n", i+1, computeTax(grossInc[i]));
	
	}

/* Prints net monthly salary for each employee */
	
	for (i = 0; i < EMPLOYEE; i++)
	{
	/*populate the netInc array , then divide net income by 12 to get monthly salary */	
	netInc[i] = grossInc[i] - computeTax(grossInc[i]);
	printf("Net monthly salary earned by employee No. %d is: EUR %.d\n", i+1, netInc[i]/12 );
	
	}

/* Finds and prints the highest net annual income , along with its associated tax .*/
	int max , counter ;
	max = counter =0;
	for (i = 0; i < EMPLOYEE; i++)
	{
	
		if (max < netInc[i] ) 
		{
			max = netInc[i];
			counter = i;
		}
	}
	printf("Highest annual Net Income earned by employee No. %d , \nin the amount of EUR %d , after EUR %d of tax were withheld.",counter+1, max, computeTax(grossInc[counter]));
	return (0);

}

