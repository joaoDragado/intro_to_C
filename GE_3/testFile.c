#include <stdio.h>
#include <math.h>

/* global variables */
int size, N ;

/* functions */
void read_frequencies(int F[][N], int Q[], int size)
{
	int i,j;
	// Populate the F array
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("Δώσε την συχνότητα εμφάνισης του όρου %d στο κείμενο %d:",i+1,j+1);
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
		printf("Δώσε την συχνότητα εμφάνισης του όρου %d στο ερώτημα q: ", i+1);
		scanf("%d",&Q[i]);
			while (Q[i] < 0)
			{
			printf("Δεν επιτρέπονται μη αρνητικές τιμές. Ξαναπροσπαθήστε :");
			scanf("%d",&Q[i]);
			}
	}
//test finction
for (i = 0; i < size; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ",F[i][j]);
			
		}
	}
for (i = 0; i < ; i++)
{
	printf("%d ",Q[i]);
}
		
}

//void invert_frequencies(int F [][N], double idf[], int size)
//{
	//int i, j;
	//double freq = 0;
	
	////iterate through tokens
	//for (i = 0; i < size; i++)
	//{
		////iterate through texts
		//for (j = 0; j < N; j++)
		//{
		    //// record occurences for the token in each text 
		    //if (F[i][j]>0) freq +=1;	
		//}
		//// compute the inverse frequency for the token
		//idf[i] = size / freq ;	
	//}
//}

//void report_query(int F[][N], int Q[], double idf[], double similarity[N], int size)
//{
	//int i,j;
	//double wText[size][N], wQuery[size], numeratorSum, wTxtSqrd, wQrSqrd;
	
	//for (j = 0; j < N; j++)
		//{
			//numeratorSum = wTxtSqrd = wQrSqrd = 0;
			//for (i = 0; i < size; i++)
			//{
				//wText[i][j] = F[i][j]*idf[i];
				//wQuery[i] = Q[i]*idf[i];
				//numeratorSum += wText[i][j] * wQuery[i];
				//wTxtSqrd += pow(wText[i][j], 2.0); //(wText[i][j])*(wText[i][j]);
				//wQrSqrd +=  pow(wQuery[i], 2.0); //(wQuery[i])*(wQuery[i]);
			//}
			//similarity[j] = numeratorSum / ( sqrt(wTxtSqrd) * sqrt(wQrSqrd)	); 
			//printf("Κείμενο d%d: ",j+1);
		//}
//}


/*	main function */
int main(void)
{
	//local variables
	N = 3;
	int F[size][N], Q[size];
	double idf[size], similarity[N];
	
	//Entering token frequencies in texts and queries
	read_frequencies(F, Q, 4);
	
	
	
	//Calculate invert frequency indexes for each token
	//invert_frequencies(F, idf, size);
	
	//printf("\n Ομοιότητες:\n");
	
	////calculate and return Degree of similarity for each text
	//report_query( F, Q, idf, similarity, size);
	
	return (0);
}
