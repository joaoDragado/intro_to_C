/*
Αρχείο: 03_arxeia_dyadika_diaxorismos.c
Πρόβλημα: Διάβασμα δεδομένων από δυαδικά αρχεία και διαχωρισμός των δεδομένων σε 3 αρχεία
Λύση: Στο arxeio_proor1.txt αποθηκεύονται οι αριθμοί 0..9
Στο arxeio_proor2.txt αποθηκεύονται οι αριθμοί 10..19
Στο arxeio_proor3.txt αποθηκεύονται οι αριθμοί 20..40

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *arxeio_pigi;
	FILE *arxeio_proor1;
	FILE *arxeio_proor2;
	FILE *arxeio_proor3;
	int seira_akeraion[20];
	int temp_seira_akeraion;
	int j;

    // ʼνοιγμα αρχείων για εγγραφή
	arxeio_pigi = fopen("arxeio_pigi.bin", "w+");
	arxeio_proor1 = fopen("arxeio_proor1.bin", "w+");
	arxeio_proor2 = fopen("arxeio_proor2.bin", "w+");
	arxeio_proor3 = fopen("arxeio_proor3.bin", "w+");

    // Εισαγωγή δεδομένων στον πίνακα seira_akeraion
	for (j=0;j<20;j++)
	{
		seira_akeraion[j] = 2*j;
	}

    // Εγγραφή δεδομένων στο αρχείο
	if (!fwrite(seira_akeraion, (sizeof(int)*20), 1, arxeio_pigi))
		printf("Error seira_akeraion\n");

    // Κλείσιμο αρχείου
	fclose(arxeio_pigi);

	// ʼνοιγμα αρχείου για ανάγνωση
	arxeio_pigi = fopen("arxeio_pigi.bin", "r");

    // Εκτύπωση περιεχομένων του αρχείου arxeio_pigi
	printf("To periexomeno tou arxeiou \"arxeio_pigi.bin\" einai:");
	while(!feof(arxeio_pigi))
	{
		if(fread(&temp_seira_akeraion, sizeof(temp_seira_akeraion), 1, arxeio_pigi))
		{
			printf("%d ", temp_seira_akeraion);
		}
		if (temp_seira_akeraion<=9)
		{
			fwrite(&temp_seira_akeraion, sizeof(temp_seira_akeraion), 1, arxeio_proor1);  // Εγγραφή στο arxeio_poor1
		}
		else if (temp_seira_akeraion<=19)
		{
			fwrite(&temp_seira_akeraion, sizeof(temp_seira_akeraion), 1, arxeio_proor2); // Εγγραφή στο arxeio_poor2
		}
		else
		{
			fwrite(&temp_seira_akeraion, sizeof(temp_seira_akeraion), 1, arxeio_proor3); // Εγγραφή στο arxeio_poor3
		}
	}
	printf("\n");

    // Κλείσιμο αρχείων
	fclose(arxeio_proor1);
	fclose(arxeio_proor2);
	fclose(arxeio_proor3);

    // ʼνοιγμα αρχείων για ανάγνωση
	arxeio_proor1 = fopen("arxeio_proor1.bin", "r");
	arxeio_proor2 = fopen("arxeio_proor2.bin", "r");
	arxeio_proor3 = fopen("arxeio_proor3.bin", "r");

    // Εκτύπωση περιεχομένων του αρχείου arxeio_poor1
	printf("To periexomeno tou arxeiou \"arxeio_proor1.bin\" einai:");
	while(!feof(arxeio_proor1))
	{
		if(fread(&temp_seira_akeraion, sizeof(temp_seira_akeraion), 1, arxeio_proor1))
			printf("%d ", temp_seira_akeraion);
	}
	printf("\n");

    // Εκτύπωση περιεχομένων του αρχείου arxeio_poor2
	printf("To periexomeno tou arxeiou \"arxeio_proor2.bin\" einai:");
	while(!feof(arxeio_proor2))
	{
		if(fread(&temp_seira_akeraion, sizeof(temp_seira_akeraion), 1, arxeio_proor2))
			printf("%d ", temp_seira_akeraion);
	}
	printf("\n");

    // Εκτύπωση περιεχομένων του αρχείου arxeio_poor1
	printf("To periexomeno tou arxeiou \"arxeio_proor3.bin\" einai:");
	while(!feof(arxeio_proor3))
	{
		if(fread(&temp_seira_akeraion, sizeof(temp_seira_akeraion), 1, arxeio_proor3))
			printf("%d ", temp_seira_akeraion);
	}
	printf("\n");

    // Κλείσιμο όλων των αρχείων
	fclose(arxeio_pigi);
	fclose(arxeio_proor1);
	fclose(arxeio_proor2);
	fclose(arxeio_proor3);
system("pause");
}
