/*
Αρχείο: 09_arxeia_keimena_example.c
Πρόβλημα: Αντιγραφή δεδομένων από αρχείο σε αρχείο. Τυπώνεται ο αριθμός των χαρακτήρων που αντιγράφηκαν
Λύση: Με χρήση της συνάρτησης fputc() η οποία γράφει ένα σύνολο χαρακτήρων σε ένα αρχείο αντιγράφουμε όλα τα στοιχεία από το ένα αρχείο στο άλλο.
Σύνταξη: fputs(char *str, FILE *fp)
Ο δείκτης str δείχνει την πρώτη θέση του συνόλου χαρακτήρων προς εγγραφή και ο δείκτης fp καθορίζει το αρχείο.
Έννοιες που συναντάμε: fputc(), fopen(), fclose(), feof()
*/

#include <stdio.h>
#include <stdlib.h>

void antigrafi_arxeion(char source_file_name[], char dest_file_name[])
{
	char xaraktiras;
	int counter = 0;
	FILE *source_file;
	FILE *dest_file;

	if(!(source_file = fopen( source_file_name, "r" )))
	{
      printf("Error opening the file %s\n", source_file_name);
      return;
      }
	if(!(dest_file = fopen( dest_file_name, "w" )))
{     printf("Error opening the file %s\n", dest_file_name);
      return;
}
	/* Epanalipsi mexri to telos tou arxeiou: */
	while(!feof( source_file ))
	{
		xaraktiras = fgetc(source_file);
		fputc(xaraktiras,dest_file);
		counter++;
	}

	printf("Antigrafthikan %d xaraktires\n", counter);
	
	fclose( source_file );
	fclose( dest_file );

}

int main( )
{
	char source_file_name[100];
	char dest_file_name[100];

	printf("Eisagete to onoma tou arxeiou pigis me tin kataliksi .txt px test.txt\n");
	gets(source_file_name);

	printf("Eisagete to onoma tou arxeiou proorismou\n");
	gets(dest_file_name);

	antigrafi_arxeion(source_file_name, dest_file_name);
    system("pause");
}

