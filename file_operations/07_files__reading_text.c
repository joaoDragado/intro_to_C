/* 
Αρχείο: 07_arxeia_keimena_anagnosi.c
Πρόβλημα: Διάβασμα μορφοποιημένων δεδομένων από αρχείο
Λύση: Διάβασμα εγγραφών ακέραιων και πλήθους εγγραφών καθώς και εκτύπωση του αθροίσματος τους. Σύνταξη:
int fscanf(FILE *fp, char *morfi, address). 
Έννοιες που συναντάμε: fscanf()

*/ 

#include <stdio.h>
#include <stdlib.h>

#define onoma_arxeiou "numbers.txt"

int main ()
{
	FILE *arxeio;
	int arithmos,athroisma,plithos;
	athroisma=0;
	plithos=0;

	if(!(arxeio=fopen(onoma_arxeiou,"r")))
	{
		printf ("Error opening file: %s\n",onoma_arxeiou);
    	system("pause");
		return;
	}

	while(!feof(arxeio)) 
	{
 		fscanf(arxeio,"%d\n",&arithmos);
		athroisma+=arithmos;
		plithos++;
		 
	}

	fclose(arxeio);
	
	printf ( "Plithos:%d\n" , plithos) ; 
	printf ( "Athroisma:%d\n", athroisma) ;
	system("pause");
} 
