/*****************************************************************************
 * ΠΛΗ10 
 * Εισαγωγή στη γλώσσα προγραμματισμού C.
 * 
 * 26o Αρχείο: 26_daysMonth.c
 *
 * Αυτό είναι το εικοστό έκτο πρόγραμμα προς επίδειξη.
 * Πρόβλημα: Υπολογισμός των ημερών που έχει ένας μήνας, 
 * πριν προλάβει ο χρήστης να πληκτρολογήσει όλους τους χαρακτήρες που αποτελούν το όνομά του. 
 * Λύση: Καθώς ο χρήστης ξεκινάει να εισάγει το όνομα ενός μήνα, 
 * ελέγχουμε έναν-έναν τους χαρακτήρες και παρουσιάζουμε το πλήθος 
 * των ημερών του μήνα, αμέσως μόλις αυτό γίνει διακριτό. 
 * Έννοιες που συναντάμε: Έλεγχος πολλαπλής συνθήκης, συναρτήσεις getch() και putchar().
 ****************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

main()
{
    system("chcp 1253>nul");
    int yr,days=0;
    char ch;
    printf("\nΔώστε το όνομα ενός μήνα (* για τέλος): ");
    while( (ch = getch() ) != '*' )
   {
    putchar(ch);
    switch (ch)
    {
    case 'σ':
    case 'Σ':
    case 'ν':
    case 'Ν': days=30;
	      break;
    case 'μ':
    case 'Μ':
    case 'ο':
    case 'Ο':
    case 'δ':
    case 'Δ': days=31;
	      break;
    case 'α':
    case 'Α': ch=getch(); putchar(ch);
	      switch (ch)
	      {
	      case 'υ':
          case 'ύ':
	      case 'Υ': days=31;
			break;
	      case 'π':
	      case 'Π': days=30;
			break;
	      
	      }
	      break;
    case 'ι':
    case 'Ι': ch=getch(); putchar(ch);
	      switch (ch)
	      {
	      case 'α':
	      case 'Α': days=31;
			break;
	      case 'ο':
	      case 'Ο': ch=getch(); putchar(ch); 
            ch=getch(); putchar(ch);
			switch (ch)
			{
			case 'ν':
			case 'Ν': days=30;
				  break;
			case 'λ':
			case 'Λ': days=31;
				  break;
		
			}
			break;
	     
	       }
	       break;
    case 'φ':
    case 'Φ': printf("\nΔώστε τη χρονιά: ");
	      scanf("%d",&yr);
	      if (yr % 4 == 0 && yr % 100 != 0)    
		days=29;
	      else if (yr % 400 == 0)
		days=28;
	      break;
   
    }
    if (days != 0) printf("\nέχει %d μέρες\n",days);
    else
      printf("\nΔεν υπάρχει τέτοιος μήνας\n");
    days=0;
    printf("\nΔώστε το όνομα ενός μήνα (* για τέλος):");
   }
   printf("\n");
   system("pause");
}
