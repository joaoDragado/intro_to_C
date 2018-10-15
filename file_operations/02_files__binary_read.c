/*
Αρχείο: 02_arxeia_dyadika_anagnosi.c
Πρόβλημα: Πως διαβάζουμε και γράφουμε δυαδικά αρχεία
Λύση: Τα αρχεία που αποτελούνται από εγγραφές ίδιου μήκους επιτρέπουν τυχαία προσπέλαση στα δεδομένα που περιέχουν
Έννοιες που συναντάμε: feof() - επιστρέφει 1 όταν έχουμε φτάσει στο τέρμα του αρχείου και 0 σε άλλη περίπτωση,
fread, fopen, fclose - κλείνει το αρχείο που έχει ανοιχτεί με την fopen
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *arxeioA;
	FILE *arxeioB;
	FILE *arxeioC;
	char seira1[20];
	char temp_seira1;
	int seira2[5];
	int temp_seira2;
	int akeraios = 2;
	int temp_akeraios;
	int j,k;

	arxeioA = fopen("arxeio1.txt", "w+");  // ʼνοιγμα αρχείου
	arxeioB = fopen("arxeio2.txt", "w+");  // ʼνοιγμα αρχείου
	arxeioC = fopen("arxeio3.txt", "w+");  // ʼνοιγμα αρχείου

    // Συμπλήρωση των μονοδιάστατων πινάκων seira1 και seira2
	for (j=0;j<20;j++)
	{
		seira1[j] = 'a';  // Το σύμβολο 'a' τοποθετείται σε όλες τις θέσεις του πίνακα χαρακτήρων
	}
	for (k=0;k<5;k++)
	{
		seira2[k] = 2*k;  // Τοποθετείται το διπλάσιο του αριθμού k
	}

    // Εγγραφή δεδομένων στα αρχεία. Σε περίπτωση αποτυχίας η fwrite επιστρέφει μηδενική τιμή.
	if (!fwrite(seira1, (sizeof(char)*20), 1, arxeioA))
		printf("Error seira1\n");
	if (!fwrite(seira2, (sizeof(int)*5), 1, arxeioB))
		printf("Error seira2\n");
	if (!fwrite(&akeraios, sizeof(akeraios), 1, arxeioC))
		printf("Error akeraios\n");

    // Κλείσιμο των αρχείων
	fclose(arxeioA);
	fclose(arxeioB);
	fclose(arxeioC);

	// Εκ νέου άνοιγμα των αρχείων
	arxeioA = fopen("arxeio1.txt", "r");
	arxeioB = fopen("arxeio2.txt", "r");
	arxeioC = fopen("arxeio3.txt", "r");

    // Εκτύπωση στην οθόνη των περιεχομένων του αρχείου arxeioA
	printf("To periexomeno tou arxeiou \"arxeio1.txt\" einai:");
	while(!feof(arxeioA))
	{
		if(fread(&temp_seira1, sizeof(char), 1, arxeioA))
			printf("%c", temp_seira1);
	}
	printf("\n");

    // Εκτύπωση στην οθόνη των περιεχομένων του αρχείου arxeioB
	printf("To periexomeno tou arxeiou \"arxeio2.txt\" einai:");
	while(!feof(arxeioB))
	{
		if(fread(&temp_seira2, sizeof(temp_seira2), 1, arxeioB))
			printf("%d", temp_seira2);
	}
	printf("\n");

    // Εκτύπωση στην οθόνη των περιεχομένων του αρχείου arxeioC
	while(!feof(arxeioC))
	{
		fread(&temp_akeraios, sizeof(temp_akeraios), 1, arxeioC);
	}
	printf("To periexomeno tou arxeiou \"arxeio3.txt\" einai:%d\n", temp_akeraios);

    //  Κλείσιμο αρχείων
	fclose(arxeioA);
	fclose(arxeioB);
	fclose(arxeioC);

	system("pause");
}
