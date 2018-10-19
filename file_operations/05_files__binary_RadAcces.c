/* 
Αρχείο: 05_arxeia_dyadika_RadAcces.c
Πρόβλημα: Προσπέλαση δεδομένων σε δυαδικά αρχεία. Να εντοπιστούν και να τυπωθούν οι ζυγές εγγραφές αρχίζοντας από το τέλος
Λύση: Η fseek() τοποθετεί το δείκτη του αρχείου σε κάποιο σημείο του αρχείου.
Σύνταξη: int fseek(FILE *fp, long int apostasi, int thesi)
*fp: δείκτης σε αρχείο
Η παράμετρος apostasy δηλώνει την απόσταση σε byte από τη θέση που καθορίζει η παράμετρος thesi. Παράδειγμα:
fp = fopen("arxeio", "rb");
fseek(fp,100,0);
Η fseek τοποθετεί το δείκτη θέσης του αρχείου στο 100 byte
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int int_size = sizeof(int);
	FILE *arxeio;

	int seira_akeraion[10];
	int j,temp_akeraios;

	arxeio = fopen("arxeio.txt", "w+");

	seira_akeraion[0] = 10;
	seira_akeraion[1] = 22;
	seira_akeraion[2] = 25;
	seira_akeraion[3] = 43;
	seira_akeraion[4] = 54;
	seira_akeraion[5] = 56;
	seira_akeraion[6] = 67;
	seira_akeraion[7] = 76;
	seira_akeraion[8] = 77;
	seira_akeraion[9] = 99;

	fwrite(seira_akeraion, (int_size*10), 1, arxeio);

	fclose(arxeio);

	arxeio = fopen("arxeio.txt", "r");

	fseek(arxeio, -int_size, SEEK_END);

	printf("Oi epithimites egrafes tou arxeiou \"arxeio.txt\" einai:");
	for(j=0;j<5;j++)
	{
		if(fread(&temp_akeraios, sizeof(temp_akeraios), 1, arxeio))
			printf("%d ", temp_akeraios);

		fseek(arxeio, -3*int_size, SEEK_CUR);
	}
	printf("\n");
	
	fclose(arxeio);
    system("pause"); 
}
