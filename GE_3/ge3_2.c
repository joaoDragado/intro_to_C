#include <stdio.h>
#include <string.h>

#define N	8	// πλήθος Ν των κριτηρίων
#define M 3	//αριθμό Μ των χωρών
//περιγραφές των κριτηρίων
const char *criterion[] = {"Κυβερνητική σταθερότητα","Σταθερότητα εθνικού νομίσματος","Φορολογική πολιτική","Εγγύτητα σε αγορές","Εγγύτητα σε προμηθευτές","Μορφωτικό επίπεδο εργαζομένων","Κουλτούρα, νοοτροπία, παραγωγικότητα","Κόστος εργασίας"} ;   
int weights[N];		// συντελεστές βαρύτητας κάθε κριτηρίου.
int scores[N][M];		// βαθμολογία κάθε χώρας ανά κριτήριο.
int finalScores[M];	// τελικό βαθμό για κάθε χώρα.

/*συναρτηση για την εμφανιση σειρας ομοιων χαρακτηρων */

void characters(int n, char ch)
{ int i;
for (i=0; i<n; i++) printf("%c", ch);
printf("\n");
}


/* συνάρτηση read_weights() διαβάζει από το πληκτρολόγιο τους συντελεστές βαρύτητας του πίνακα weights , αποδεκτές τιμές μη αρνητικοί ακέραιοι μικρότεροι του 100 */

void read_weights()
{
	int i,sum =0;
	for (i = 0; i < N; i++)
	{
	printf("Συντελεστής Βαρύτητας για το κριτήριο %d (%s): ",i+1,criterion[i] );	
	scanf("%d",&weights[i]);
	while (weights[i]<0 || weights[i]>100)	//αμυντικός προγραμματισμός
			{
			printf("Δεν επιτρέπονται αρνητικές τιμές.Ξαναπροσπαθήστε\n");
			scanf("%d",&weights[i]);
			}
	sum+=weights[i];
	printf("SUM(Wj)= %d\n",sum);		
	}	
	while (sum !=100)		//αμυντικός προγραμματισμός
		{
		printf("Το άθροισμα των συντελεστών πρέπει είναι 100. Επανεκκίνηση ρουτίνας.\n");
		read_weights();
		}
}

/* συνάρτηση read_scores() διαβάζει από το πληκτρολόγιο τις βαθμολογίες κάθε χώρας για κάθε κριτήριο και καταχωρεί στον πίνακα scores. Καταχώρηση βαθμών στον πίνακα γίνεται κατά στήλη. Αποδεκτοί οι ακέραιοι θετικοί αριθμοί μικρότεροι ή ίσοι του 5. */

void read_scores()
{
	int i,j;
	for (j = 0; j < M; j++)		// iterate through countries
	{
		characters(20,'-');		// add delimiter line
		for (i = 0; i < N; i++)	// iterate through criteria
		{
			printf("Βαθμός στο κριτήριο %d για τη χώρα %d: ",i+1, j+1);	
	scanf("%d",&scores[i][j]);
	while (scores[i][j]<0 || scores[i][j]>5)		//αμυντικός προγραμματισμός
			{
			printf("Τιμή εκτός ορίου [0,5].Ξαναπροσπαθήστε\n");
			scanf("%d",&scores[i][j]);
			}
		}
	}
}

/* συνάρτηση best_country() υπολογίζει τελικό βαθμό για κάθε χώρα και αποθηκεύει στον πίνακα finalScores */

void best_country()
{
	int i,j,cScore, maxScore,index;
	maxScore = index = 0;		//initialize variables
	for (j = 0; j < M; j++)		// iterate through countries
	{
		cScore = 0;
		for (i = 0; i < N; i++)		// iterate through criteria
		{
				cScore += weights[i]*scores[i][j];	// use formula given to compute score
		}
		finalScores[j] = cScore ;			// add to array 
		printf("Τελικός βαθμός για τη χώρα %d:\t %d\n",j+1,cScore); 
		if ( maxScore < cScore) maxScore = cScore; 	// if score is the highest one yet, set maxScore to that value
	}
	characters(20,'-');		// add delimiter line
	printf("Η/Οι χώρα/ες με την υψηλότερη βαθμολογία είναι η/οι : ");
	for (i = 0; i < M; i++)		// iterate through countries
	{
		if (finalScores[i] == maxScore) printf("%d ",i+1); // find highest score and print its index(es)
	}
}

int main(void)
{
	read_weights();
	read_scores();
	characters(20,'-');		// add delimiter line
	best_country();
	
	return (0);
}







 
