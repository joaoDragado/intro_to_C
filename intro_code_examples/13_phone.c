﻿/************************************************************
* ΠΛΗ10
* Εισαγωγή στη γλώσσα προγραμματισμού C.
* 
* 13o Αρχείο: 13_phone.c
*
* Αυτό είναι το δέκατο τρίτο πρόγραμμα προς επίδειξη. Το πρόγραμμα 
* παρουσιάζει τις βασικές επαναληπτικές δομές for και while. 
*************************************************************/

#include <stdio.h>
#define plithos 100
main()
{
	int x, f[10], a, count, i; // Δήλωση πίνακα και λοιπών μεταβλητών
	for (i=0;i < 10;i++) // Αρχικοποίηση του πίνακα με τιμή ανάθεσης για το κάθε κελί 0.
		f[i]=0;
	scanf ("%d", &x); // Διάβασμα μεταβλητής- δευτερόλεπτα κλήσης
	count=0;
	while ((x >= 1) && (x < 600) && (count < plithos)) // Ελέγχουμε αν ο δοθέν αριθμός ανήκει στο αποδεκτό πλαίσιο αριθμών
	{
		a=x/60; // Μετατρέπουμε τα δευτερόλεπτα σε λεπτά
		f[a]=f[a]+1; // Αύξηση συχνότητας
		count++;
		scanf("%d", &x); // Διάβασμα επόμενου αριθμού
	}
	printf("Duration in minutes \t Frequency\n"); // Εκτύπωση αποτελεσμάτων
	for (i=0;i < 10;i++)
		if (f[i] > 0)
			printf("%d \t\t\t %d\n",i,f[i]);
}
