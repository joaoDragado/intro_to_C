/*
Αρχείο: 03_arxeia_dyadika_diaxorismos.c
Πρόβλημα: Διάβασμα δεδομένων από δυαδικά αρχεία και διαχωρισμός των δεδομένων σε 3 αρχεία
Λύση: Στο record_dest1.txt αποθηκεύονται οι αριθμοί 0..9
Στο record_dest2.txt αποθηκεύονται οι αριθμοί 10..19
Στο record_dest3.txt αποθηκεύονται οι αριθμοί 20..40

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *record_source;
	FILE *record_dest1;
	FILE *record_dest2;
	FILE *record_dest3;
	int seq_int[20];
	int temp_seq_int;
	int j;

    // ʼνοιγμα αρχείων για εγγραφή
	record_source = fopen("record_source.bin", "w+");
	record_dest1 = fopen("record_dest1.bin", "w+");
	record_dest2 = fopen("record_dest2.bin", "w+");
	record_dest3 = fopen("record_dest3.bin", "w+");

    // Εισαγωγή δεδομένων στον πίνακα seq_int
	for (j=0;j<20;j++)
	{
		seq_int[j] = 2*j;
	}

    // Εγγραφή δεδομένων στο αρχείο
	if (!fwrite(seq_int, (sizeof(int)*20), 1, record_source))
		printf("Error seq_int\n");

    // Κλείσιμο αρχείου
	fclose(record_source);

	// ʼνοιγμα αρχείου για ανάγνωση
	record_source = fopen("record_source.bin", "r");

    // Εκτύπωση περιεχομένων του αρχείου record_source
	printf("To periexomeno tou recordu \"record_source.bin\" einai:");
	while(!feof(record_source))
	{
		if(fread(&temp_seq_int, sizeof(temp_seq_int), 1, record_source))
		{
			printf("%d ", temp_seq_int);
		}
		if (temp_seq_int<=9)
		{
			fwrite(&temp_seq_int, sizeof(temp_seq_int), 1, record_dest1);  // Εγγραφή στο record_poor1
		}
		else if (temp_seq_int<=19)
		{
			fwrite(&temp_seq_int, sizeof(temp_seq_int), 1, record_dest2); // Εγγραφή στο record_poor2
		}
		else
		{
			fwrite(&temp_seq_int, sizeof(temp_seq_int), 1, record_dest3); // Εγγραφή στο record_poor3
		}
	}
	printf("\n");

    // Κλείσιμο αρχείων
	fclose(record_dest1);
	fclose(record_dest2);
	fclose(record_dest3);

    // ʼνοιγμα αρχείων για ανάγνωση
	record_dest1 = fopen("record_dest1.bin", "r");
	record_dest2 = fopen("record_dest2.bin", "r");
	record_dest3 = fopen("record_dest3.bin", "r");

    // Εκτύπωση περιεχομένων του αρχείου record_poor1
	printf("To periexomeno tou recordu \"record_dest1.bin\" einai:");
	while(!feof(record_dest1))
	{
		if(fread(&temp_seq_int, sizeof(temp_seq_int), 1, record_dest1))
			printf("%d ", temp_seq_int);
	}
	printf("\n");

    // Εκτύπωση περιεχομένων του αρχείου record_poor2
	printf("To periexomeno tou recordu \"record_dest2.bin\" einai:");
	while(!feof(record_dest2))
	{
		if(fread(&temp_seq_int, sizeof(temp_seq_int), 1, record_dest2))
			printf("%d ", temp_seq_int);
	}
	printf("\n");

    // Εκτύπωση περιεχομένων του αρχείου record_poor1
	printf("To periexomeno tou recordu \"record_dest3.bin\" einai:");
	while(!feof(record_dest3))
	{
		if(fread(&temp_seq_int, sizeof(temp_seq_int), 1, record_dest3))
			printf("%d ", temp_seq_int);
	}
	printf("\n");

    // Κλείσιμο όλων των αρχείων
	fclose(record_source);
	fclose(record_dest1);
	fclose(record_dest2);
	fclose(record_dest3);
system("pause");
}
