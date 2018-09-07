/****************************************************************************
 * ΠΛΗ10 
 * Εισαγωγή στη γλώσσα προγραμματισμού C.
 * 
 * 21o Αρχείο: 21_malloc.c
 *
 * Αυτό είναι το εικοστό πρώτο πρόγραμμα προς επίδειξη. 
 * Πρόβλημα: Ακόμα ένα παράδειγμα δυναμική διαχείριση μνήμης. 
 * Λύση: Η χρήση της malloc() δεσμεύει από το σωρό ένα τμήμα μνήμης μεγέθους σε 
 * bytes και επιστρέφει τη διεύθυνση της πρώτης θέσης μνήμης του block που δέσμευσε. 
 * Αν η δέσμευση μνήμης αποτύχει επιστρέφεται NULL. Παράδειγμα: p=(char *) malloc(8);
 * Έννοιες που συναντάμε: malloc()
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *metabliti;
	metabliti = (char*)malloc(61*sizeof(char)); /* not forgetting the null */
	
	if (metabliti == NULL)
	{
		printf("ERROR:No space available exists\n");
		exit(EXIT_FAILURE);
	}

	printf("Allocation of dynamic memory succeeded!!!\n");

	strcpy (metabliti, "Use the \"metabliti\" variable for up to 60 characters");

	printf("%s\n", metabliti);

	metabliti = NULL;
    system("pause");
	return 0;
}
