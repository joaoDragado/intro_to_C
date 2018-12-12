/*
Αρχείο: 04_arxeia_dyadika_example.c
Πρόβλημα: Παράδειγμα αποθήκευσης στοιχείων σε δυαδικά αρχεία. Τυχαία προσπέλαση αρχείων
Λύση: Η fwrite() γράφει έναν αριθμό από τμήματα συγκεκριμένου αριθμού byte σε μια περιοχή προσωρινής αποθήκευσης (buffer) και τα αποθηκεύει σε ένα αρχείο.
Σύνταξη: int fwrite(void *buffer, int no_of_bytes, plithos, FILE *fp)
no_of_bytes τον αριθμό bytes του κάθε τμήματος
plithos: το πλήθος των τμημάτων
*fp: δείκτης σε αρχείο
Έννοιες που συναντάμε: fwrite()

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *recordA;
	FILE *recordB;
	FILE *recordC;
	char sequence1[20];
	int sequence2[5];
	int integer = 33;

    // Άνοιγμα αρχείων
	recordA = fopen("record1.bin", "w");
	recordB = fopen("record2.bin", "w");
	recordC = fopen("record3.bin", "w");


	if (!fwrite(sequence1, (sizeof(char)*20), 1, recordA))    // Εγγραφή δεδομένων στο recordA
		printf(" Error sequence1\n");
	if (!fwrite(sequence2, (sizeof(int)*5), 1, recordB))      // Εγγραφή δεδομένων στο recordB
		printf(" Error sequence2\n");
	if (!fwrite(&integer, sizeof(integer), 1, recordC))  // Εγγραφή δεδομένων στο recordC
		printf(" Error integer\n");
		system("pause");
}
