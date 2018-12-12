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
	FILE *recordA;
	FILE *recordB;
	FILE *recordC;
	char sequence1[20];
	char temp_sequence1;
	int sequence2[5];
	int temp_sequence2;
	int akeraios = 2;
	int temp_akeraios;
	int j,k;

	recordA = fopen("record1.txt", "w+");  // ʼνοιγμα αρχείου
	recordB = fopen("record2.txt", "w+");  // ʼνοιγμα αρχείου
	recordC = fopen("record3.txt", "w+");  // ʼνοιγμα αρχείου

    // Συμπλήρωση των μονοδιάστατων πινάκων sequence1 και sequence2
	for (j=0;j<20;j++)
	{
		sequence1[j] = 'a';  // Το σύμβολο 'a' τοποθετείται σε όλες τις θέσεις του πίνακα χαρακτήρων
	}
	for (k=0;k<5;k++)
	{
		sequence2[k] = 2*k;  // Τοποθετείται το διπλάσιο του αριθμού k
	}

    // Εγγραφή δεδομένων στα αρχεία. Σε περίπτωση αποτυχίας η fwrite επιστρέφει μηδενική τιμή.
	if (!fwrite(sequence1, (sizeof(char)*20), 1, recordA))
		printf("Error sequence1\n");
	if (!fwrite(sequence2, (sizeof(int)*5), 1, recordB))
		printf("Error sequence2\n");
	if (!fwrite(&akeraios, sizeof(akeraios), 1, recordC))
		printf("Error akeraios\n");

    // Κλείσιμο των αρχείων
	fclose(recordA);
	fclose(recordB);
	fclose(recordC);

	// Εκ νέου άνοιγμα των αρχείων
	recordA = fopen("record1.txt", "r");
	recordB = fopen("record2.txt", "r");
	recordC = fopen("record3.txt", "r");

    // Εκτύπωση στην οθόνη των περιεχομένων του αρχείου recordA
	printf("To periexomeno tou recordu \"record1.txt\" einai:");
	while(!feof(recordA))
	{
		if(fread(&temp_sequence1, sizeof(char), 1, recordA))
			printf("%c", temp_sequence1);
	}
	printf("\n");

    // Εκτύπωση στην οθόνη των περιεχομένων του αρχείου recordB
	printf("To periexomeno tou recordu \"record2.txt\" einai:");
	while(!feof(recordB))
	{
		if(fread(&temp_sequence2, sizeof(temp_sequence2), 1, recordB))
			printf("%d", temp_sequence2);
	}
	printf("\n");

    // Εκτύπωση στην οθόνη των περιεχομένων του αρχείου recordC
	while(!feof(recordC))
	{
		fread(&temp_akeraios, sizeof(temp_akeraios), 1, recordC);
	}
	printf("To periexomeno tou recordu \"record3.txt\" einai:%d\n", temp_akeraios);

    //  Κλείσιμο αρχείων
	fclose(recordA);
	fclose(recordB);
	fclose(recordC);

	system("pause");
}
