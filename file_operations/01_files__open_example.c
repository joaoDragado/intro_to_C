/*
Αρχείο: 01_arxeia_anoigma_example.c
Πρόβλημα: Πως χειριζόμαστε αρχεία. Το άνοιγμα του αρχείου
Λύση: Η fopen() ανοίγει ένα αρχείο και επιστρέφει ένα δείκτη τύπου FILE. Ο γενικός τρόπος χρήσης είναι
	FILE *myFile1;
	myFile1 = fopen(record, τρόπος);
Ο τρόπος w+ δηλώνει άνοιγμα αρχείου κειμένου για ανάγνωση/εγγραφή
Αν το άνοιγμα αποτύχει επιστρέφεται NULL
Έννοιες που συναντάμε: fopen
*/

#include <stdio.h>
#include <stdlib.h>

#define arxeio1 "record1.txt"

int main ()
{
	FILE *myFile1, *myFile2, *myFile3;  // Δηλώσεις των μεταβλητών των αρχείων
	char record2[16] = "record2.txt";

	myFile1 = fopen(record1, "w+");        // άνοιγμα πρώτου αρχείου
	myFile2 = fopen(record2, "w+");        // άνοιγμα δεύτερου αρχείου
	myFile3 = fopen("record3.txt", "w+");  // άνοιγμα τρίτου αρχείου

	if (!myFile1)  // Αποτυχία ανοίγματος αρχείου (η τιμή του myFile1 είναι μηδενική)
		printf("Error opening \"myFile1\"\n");
	else
		printf("\"myFile1\" opened successfully\n");

	if (!myFile2) // Αποτυχία ανοίγματος αρχείου (η τιμή του myFile2 είναι μηδενική)
		printf("Error opening \"myFile2\"\n");
	else
		printf("\"myFile2\" opened successfully\n");

	if (!myFile3) // Αποτυχία ανοίγματος αρχείου (η τιμή του myFile3 είναι μηδενική)
		printf("Error opening \"myFile3\"\n");
	else
		printf("\"myFile3\" opened successfully\n");

  system("pause");
}
