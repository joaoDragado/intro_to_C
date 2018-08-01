#include <stdio.h>
#include <math.h>

/* global variables */
const int size=4;
const int N=3;

/* functions */
void read_frequencies(int F[][N], int Q[], int size)
{
	int i,j;
	// Populate the F array
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("Δώσε την συχνότητα εμφάνισης του όρου t%d στο κείμενο d%d:",i,j);
			scanf("%d",&F[i][j]);
			while (F[i][j] < 0)
			{
			printf("Δεν επιτρέπονται μη αρνητικές τιμές. Ξαναπροσπαθήστε :");
			scanf("%d",&F[i][j]);
			}
		}
	}
	// Populate the Q array
	for (i = 0; i < size; i++)
	{
		printf("Δώσε την συχνότητα εμφάνισης του όρου t%d στο ερώτημα q: ", i);
		scanf("%d",&Q[i]);
			while (Q[i] < 0)
			{
			printf("Δεν επιτρέπονται μη αρνητικές τιμές. Ξαναπροσπαθήστε :");
			scanf("%d",&Q[i]);
			}
	}

}

void invert_frequencies(int F [][N], double idf[], int size)
{
	int i, j;
	double freq;

	//iterate through tokens
	for (i = 0; i < size; i++)
	{
		freq =0.0;
		//iterate through texts
		for (j = 0; j < N; j++)
		{
		    // record occurences for the token in each text
		    if (F[i][j]>0) freq +=1.0;
		}
		// compute the inverse frequency for the token
		idf[i] = size / freq ;
	}
}

void report_query(int F[][N], int Q[], double idf[], double similarity[N], int size)
{
	int i,j;
	double wText[size][N], wQuery[size], numeratorSum, wTxtSqrd, wQrSqrd;
	//initialize function variables
	numeratorSum = wTxtSqrd = wQrSqrd = 0;
	for (j = 0; j < N; j++)
		{
			for (i = 0; i < size; i++)
			{
				wText[i][j] = F[i][j]*idf[i];
				wQuery[i] = Q[i]*idf[i];
				numeratorSum += wText[i][j] * wQuery[i];
				wTxtSqrd += pow(wText[i][j], 2.0); 
				wQrSqrd +=  pow(wQuery[i], 2.0); 
			}
			similarity[j] = numeratorSum / ( sqrt(wTxtSqrd) * sqrt(wQrSqrd)	);
			printf("Κείμενο d%d:  %lf\n",j, similarity[j]);
			// reset function variables to zero 
			
			numeratorSum = wTxtSqrd = wQrSqrd = 0;
		}
}


/*	main function */
int main(void)
{
	//local variables
	int F[size][N], Q[size];
	double idf[size], similarity[N];

	//Entering token frequencies in texts and queries
	read_frequencies(F, Q, size);
	//Calculate invert frequency indexes for each token
	invert_frequencies(F, idf, size);

	printf("\nΟμοιότητες:\n");

	//calculate and return Degree of similarity for each text
	report_query( F, Q, idf, similarity, size);

	return (0);
}
