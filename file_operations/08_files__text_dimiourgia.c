/*
Αρχείο: 08_arxeia_keimena_dimiourgia.c
Πρόβλημα: Εγγραφή σε αρχείο κειμένου. Εγγραφή ακεραίων 33..122 και των εκτυπώσιμων χαρακτήρων σε κώδικα ASCII που τους αντιστοιχεί
Λύση: Με χρήση της συνάρτησης fprintf() που συμπεριφέρεται όπως printf με τη διαφορά ότι σώζει τα δεδομένα σε αρχείο
Έννοιες που συναντάμε: fprintf()
*/

#include <stdio.h>
#include <stdlib.h>

#define forLimit 122

int main( )
{
   FILE *myStream;
   int j;
   
   if(!(myStream = fopen( "test.txt", "w" )))
      printf("Error opening the file \"test.txt\"");
   else
   {
      printf("The following data will be printed in test.txt\n");
		for(j=33;j<=forLimit;j++)
		{
			printf("%d:%c\n", j, j);
         fprintf(myStream, "%d:%c\n", j, j);
		}
		
		fclose( myStream );
   }
   printf("\n\n");
   system("pause");
}
