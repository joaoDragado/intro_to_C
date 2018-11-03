/*
Αρχείο: 06_arxeia_dyadika_sigxoneusi.c
Πρόβλημα: Διάβασμα δεδομένων από δυαδικά αρχεία και συγχώνευση των δεδομένων
Λύση: Διαβάζονται τα αρχεία arxeio_pigi1, arxeio_pigi2, arxeio_pigi3 και αποθηκεύονται στο arxeio_proor
Έννοιες που συναντάμε: fread(), fwrite(), fopen(), fclose()
Το 'r' στην fopen δηλώνει άνοιγμα με σκοπό τo διάβασμα δεδομένων (read)
Το 'w' στην fopen δηλώνει άνοιγμα με σκοπό την αποθήκευση δεδομένων (write)
Αν το άνοιγμα αποτύχει επιστρέφεται NULL

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *arxeio_proor;
	FILE *arxeio_pigi1;
	FILE *arxeio_pigi2;
	FILE *arxeio_pigi3; 
	int temp_akeraios, temp_akeraios1, temp_akeraios2, temp_akeraios3;
	int runner = 0;
	int file1_ended = 0;
	int file2_ended = 0;
	int file3_ended = 0;

	arxeio_proor = fopen("arxeio_proor.bin", "w+");
	arxeio_pigi1 = fopen("arxeio_pigi1.bin", "r");
	arxeio_pigi2 = fopen("arxeio_pigi2.bin", "r");
	arxeio_pigi3 = fopen("arxeio_pigi3.bin", "r");

	while(!file1_ended || !file2_ended || !file3_ended)
	{
		if (runner == 0)
		{
			fread(&temp_akeraios1, sizeof(temp_akeraios1), 1, arxeio_pigi1);
			fread(&temp_akeraios2, sizeof(temp_akeraios2), 1, arxeio_pigi2);
			fread(&temp_akeraios3, sizeof(temp_akeraios3), 1, arxeio_pigi3);
		}

		if((temp_akeraios1<temp_akeraios2 && temp_akeraios1<temp_akeraios3 && !file1_ended) ||
			(temp_akeraios1<temp_akeraios2 && file3_ended && !file1_ended) || 
			(temp_akeraios1<temp_akeraios3 && file2_ended && !file1_ended) ||
			(file2_ended && file3_ended))
		{
			fwrite(&temp_akeraios1, sizeof(temp_akeraios1), 1, arxeio_proor);
			if (!fread(&temp_akeraios1, sizeof(temp_akeraios1), 1, arxeio_pigi1))
				file1_ended = 1;
		}
		else if((temp_akeraios2<temp_akeraios1 && temp_akeraios2<temp_akeraios3 && !file2_ended) ||
			(temp_akeraios2<temp_akeraios1 && file3_ended && !file2_ended) || 
			(temp_akeraios2<temp_akeraios3 && file1_ended && !file2_ended) ||
			(file1_ended && file3_ended))
		{
			fwrite(&temp_akeraios2, sizeof(temp_akeraios2), 1, arxeio_proor);
			if(!fread(&temp_akeraios2, sizeof(temp_akeraios2), 1, arxeio_pigi2))
				file2_ended = 1;
		}
		else if((temp_akeraios3<temp_akeraios2 && temp_akeraios3<temp_akeraios1 && !file3_ended) ||
			(temp_akeraios3<temp_akeraios2 && file1_ended && !file3_ended) || 
			(temp_akeraios3<temp_akeraios1 && file2_ended && !file3_ended) ||
			(file2_ended && file1_ended))
		{
			fwrite(&temp_akeraios3, sizeof(temp_akeraios3), 1, arxeio_proor);
			if(!fread(&temp_akeraios3, sizeof(temp_akeraios3), 1, arxeio_pigi3))
				file3_ended = 1;
		}

		runner++;
	}

	fclose(arxeio_pigi1);
	fclose(arxeio_pigi2);
	fclose(arxeio_pigi3);
	fclose(arxeio_proor); 
	
	arxeio_proor = fopen("arxeio_proor.bin", "r");

	printf("To periexomeno tou arxeiou \"arxeio_proor.bin\" einai:");
	while(!feof(arxeio_proor))
	{
		if(fread(&temp_akeraios, sizeof(temp_akeraios), 1, arxeio_proor))
			printf("%d ", temp_akeraios);
	}
	printf("\n");

	
	fclose(arxeio_proor); 
	system("pause");
}
