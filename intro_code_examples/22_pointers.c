﻿/*****************************************************************************
 * ΠΛΗ10 
 * Εισαγωγή στη γλώσσα προγραμματισμού C.
 * 
 * 22o Αρχείο: 22_deiktes.c
 *
 * Αυτό είναι το εικοστό δεύτερο πρόγραμμα προς επίδειξη.
 * Πρόβλημα: Βασικές πράξεις με πίνακες 
 * Λύση: Δυναμική ανάθεση πίνακα και διαπέραση πίνακα με χρήση δεικτών.
 * Έννοιες που συναντάμε: malloc(), free, pointers
 * Το πρόγραμμα:
 * (α) Ορίζει μια σταθερά Μ ως ακέραιο αριθμό ο οποίος είναι το μέγεθος δύο
 * μονοδιάστατων πινάκων
 * (β) Ορίζει και διαβάζει από την οθόνη τα στοιχεία δυο μονοδιάστατων πινάκων Α
 * και Β, μεγέθους Μ ο καθένας.
 * (γ) Καλεί τη συνάρτηση matrix_sum η οποία λαμβάνει ως ορίσματα δυο πίνακες και
 * το μέγεθός τους Μ και υπολογίζει και εμφανίζει το άθροισμα των ομολόγων
 * στοιχείων των πινάκων Α και Β (δηλαδή το άθροισμα Α + Β).
 * (δ) Καλεί τη συνάρτηση matrix_minus η οποία λαμβάνει ως ορίσματα δυο πίνακες
 * και το μέγεθός τους Μ και υπολογίζει και εμφανίζει τη διαφορά των ομολόγων
 * στοιχείων των πινάκων Α και Β (δηλαδή τη διαφορά Α - Β).
 * (ε) Καλεί τη συνάρτηση matrix_reverse η οποία δέχεται ως ορίσματα ένα
 * μονοδιάστατο πίνακα και το μέγεθος του πίνακα και θέτει τα στοιχεία του πίνακα στις
 * αντίστροφες θέσεις (δηλαδή το πρώτο στοιχείο του πίνακα τοποθετείται στην
 * τελευταία θέση του πίνακα, το δεύτερο στοιχείο του πίνακα τοποθετείται στην
 * προτελευταία θέση του πίνακα, κλπ). Μετά από αυτή τη μεταβολή η συνάρτηση
 * εμφανίζει τα στοιχεία του πίνακα όπως αυτά προέκυψαν.
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Synartisi matrix_sum */

void matrix_sum( int *p, int *q, int matrix_size)
{
   int k;

   printf("\n adding matrices\n");
   for (k = 0; k < matrix_size; k++ )
      printf("%dth element = %d\n", k, *(p+k) + *(q+k) );
}
   
/* Synartisi matrix_minus */

void matrix_minus( int *p, int *q, int matrix_size)
{
   int k;

   printf("\n substacting matrices\n");
   for (k = 0; k < matrix_size; k++ )
      printf("%dth element = %d\n", k, *(p+k) - *(q+k) );
}

/* Συνάρτηση matrix_reverse */

void matrix_reverse( int *p, int matrix_size)
{
   int k;
   int tmp;

   for ( k = 0; k < matrix_size/2; k++ )
   {
      tmp = *(p+k);
      *(p+k) = *(p+matrix_size-1-k);
      *(p+matrix_size-1-k) = tmp;
   }

   printf("\n matrix reversed\n");
   for ( k = 0; k < matrix_size; k++ )
      printf("%dth element = %d\n", k, *(p+k) );

   printf("\n");

}

/* Συνάρτηση main */

int main()
{
	int m_size = -1; 
	while((m_size<1) || (m_size>6))/* Δήλωση ορίων για το μέγεθος των πινάκων */
	{
		printf("Please insert the size of the matices(1-6):");
		scanf ("%d", &m_size);
	}

	
	int *a; /* Δήλωση μεταβλητής δείκτη για τον πίνακα a */
	int *b;	/* Δήλωση μεταβλητής δείκτη για τον πίνακα b */
	int i;


	a = (int*)malloc(m_size*sizeof(int));/* δυναμική ανάθεση για τον πίνακα a */
	b = (int*)malloc(m_size*sizeof(int));/* δυναμική ανάθεση για τον πίνακα b */

	for (i = 0; i < m_size; i++ )		/* Εισαγωγή στοιχείων πρώτου πίνακα */
	{
		printf("Input a[%d]\n", i);
		scanf("%d", a+i);
	}

	for (i = 0; i < m_size; i++ ) 	/* Εισαγωγή στοιχείων δεύτερου πίνακα */
	{
		printf("Input b[%d]\n", i);
		scanf("%d", b+i);
	}

	/* Κλήση συναρτήσεων */

	matrix_sum(a, b, m_size);
	matrix_minus(a, b, m_size);

	matrix_reverse(a,m_size);
	matrix_reverse(b,m_size);

	/* Ελευθέρωση χώρου και για τους δύο πίνακες */
	free (a);
	a = NULL;
	free (b);
	b = NULL;
	system("pause");
}
