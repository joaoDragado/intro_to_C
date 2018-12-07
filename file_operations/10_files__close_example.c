/*
Αρχείο: 10_arxeia_kleisimo_example.c
Πρόβλημα: Με χρήση αμυντικού προγραμματισμού σε περίπτωση που το αρχείο δεν υπάρχει ανοίγουμε και κλείνουμε αρχεία.
Λύση: Χρήση των fopen(), fclose(). Αν το άνοιγμα αποτύχει επιστρέφεται NULL
Έννοιες που συναντάμε: fopen(), fclose()
*/

#include <stdio.h>
#include <stdlib.h>

#define arxeio1 "c:\\arxeio1.txt"

int main ()
{
	FILE *myFile1, *myFile2, *myFile3;
	char arxeio2[16] = "arxeio2.txt";
	
	myFile1 = fopen(arxeio1, "w+");
	myFile2 = fopen(arxeio2, "w+");
	myFile3 = fopen("arxeio3.txt", "w+");

	if (!myFile1)
		printf("Error opening \"myFile1\"\n");
	else
		printf("\"myFile1\" opened successfully\n");

	if (!myFile2)
		printf("Error opening \"myFile2\"\n");
	else
		printf("\"myFile2\" opened successfully\n");

	if (!myFile3)
		printf("Error opening \"myFile3\"\n");
	else
		printf("\"myFile3\" opened successfully\n");

	fclose(myFile1);
	fclose(myFile2);
	fclose(myFile3);
system("pause");
}
