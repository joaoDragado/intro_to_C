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
	FILE *arxeioA;
	FILE *arxeioB;
	FILE *arxeioC;
	char seira1[20];
	int seira2[5];
	int akeraios = 33;

    // Άνοιγμα αρχείων
	arxeioA = fopen("arxeio1.bin", "w");
	arxeioB = fopen("arxeio2.bin", "w");
	arxeioC = fopen("arxeio3.bin", "w");


	if (!fwrite(seira1, (sizeof(char)*20), 1, arxeioA))    // Εγγραφή δεδομένων στο arxeioA
		printf(" Error seira1\n");
	if (!fwrite(seira2, (sizeof(int)*5), 1, arxeioB))      // Εγγραφή δεδομένων στο arxeioB
		printf(" Error seira2\n");
	if (!fwrite(&akeraios, sizeof(akeraios), 1, arxeioC))  // Εγγραφή δεδομένων στο arxeioC
		printf(" Error akeraios\n");
		system("pause");
}
