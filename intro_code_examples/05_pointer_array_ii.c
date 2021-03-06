﻿/************************************************************
 * ΠΛΗ10 
 * Εισαγωγή στη γλώσσα προγραμματισμού C.
 * 
 * 5o Αρχείο: 05_pointer_array_ii.c
 *
 * Αυτό είναι το πέμπτο πρόγραμμα προς επίδειξη. 
 * Ζητούμενο αυτής της ʼσκησης είναι να κατανοηθεί η δυνατότητα
 * διαχείρισης πινάκων μέσω δεικτών (pointers).
 * 
 ************************************************************/

# include <stdio.h>

int h[4],i,*k;

// συνάρτηση που εμφανίζει τις διευθύνσεις, τα περιεχόμενα και τις τιμές
// των μεταβλητών h (πίνακας-array) και k (δείκτης-pointer)
emfanisi()
	{
 	  printf("\n*******************************************************************\n");
 	  printf("Dieythinseis tvn k kai h: %u %u  - Paramenoun PANTA IDIES\n",&k,&h);
	  printf("Periexomena  tvn k kai h: %u %u  - Tis h einai PANTA IDIO\n",k,h);
      printf("Times        tvn k kai h: %d %d \n",*k,*h);
      printf("*******************************************************************\n");
    }

main() 
{
      printf("k: metavliti tipou pointer\n");
 	  printf("h: metvliti tipou pinaka, apotelei stathera typou pointer\n");

      k=h;       /* o δείκτης k δείχνει στον πίνακα h, για αυτό στη 2η γραμμή 
                    από τη συνάρτηση emfanisi, το περιεχόμενο της k είναι ίδιο με αυτό της
                    h. H h δείχνει σταθερά μια συγκεκριμένη διεύθυνση μνήμης. 
                    Η έκφραση h=k δεν θα ήταν σωστή, διότι ΔΕΝ μπορεί να μεταβληθεί η τιμή
                    της h (είναι σταθερά)
	             */
      emfanisi();
	            // Η τιμή του δείκτη h (τρίτη γραμμή) είναι αρχικά 0, διότι ο h ως ολικός 
                // πίνακας έχει εξ' ορισμού μηδενισμένα όλα τα στοιχεία του (άρα και το 
                // 1ο του στοιχείο).
                // Η τιμή του δείκτη k είναι 0, διότι δείχνει στο 1ο στοιχείο του h.
                	
 	  // Εισαγωγή τιμών στο πίνακα h με χρήση του pointer k
      for (i=100;i<104;i++)
 	     	*k++=i; 	// ισοδύναμο με την h[i-100]=i; 
 	          
      // ο δείκτης k, στο τέλος της for, δείχνει πλέον στην επόμενη θέση μνήμης μετά 
      // και το τελευταίαο στοιχείο του πίνακα h
      
      printf("Periexomena pinaka h - xoris xrisi pointer\n");
      for (i=0;i<4;i++)
   		    printf("%d ",h[i]);
   	  printf("\n");	
 	  
      k--;  // ο δείκτης k 'γυρίζει' μια θέση πίσω. Αλλάζει λοιπόν το περιεχόμενό του
            // (δεύτερη γραμμή), και δείχνει πλέον στο τελευταίο στοιχείο
            // του πίνακα h (με τιμή 103)
            
  	  emfanisi(); // η τιμή του δείκτη h (τρίτη γραμμή) είναι πλεόν 100, διότι ο h έχει 
                 // ως 1ο του στοιχείο τον αριθμό 100.
	 	
      k=h+1;    // η k δείχνει στην επόμενη από την αρχική (στη δεύτερη) θέση του h
                // η k μπορεί να μεταβληθεί διότι είναι μεταβλητή τύπου pointer 
                // ενώ η έκφραση  h++ δεν είναι σωστή για να 'προχωρήσουμε' μια θέση στον h
                // διότι η h είναι σταθερά 
	  emfanisi();
	         // ο δείκτης k άλλαξε το περιεχόμενό του (δεύτερη γραμμή), και δείχνει πλέον 
             // στο δεύτερο στοιχείο του πίνακα h (με τιμή 101)
      system("pause");
	  
   	  printf("\nProsthetoume 5 sti timi tou trexontos \n");
      printf("(meso k pointer) stoixeiou %d. Apotelesma: %d\n\n",*k, *k+5); 
                           // προστίθεται το 5 στη τιμή του στοιχείου που δείχνει η k
   	                       // Αν θέλαμε να 'προχωρήσουμε' 5 θέσεις, τότε βάζουμε *(k+5)
   	  
	  printf("Periexomena pinaka h - me xrisi pointer\n");
      for (i=0,k=h;i<4;i++)
	         printf("%d ",*k++);
	        // printf("%d ",*h++); δεν είναι σωστό
      printf("\n\n");
   
 /*
 * Ας περάσουμε σε πολυδιάστατο πίνακα.
 * Η απλούστερη μορφή πολυδιάστατου πίνακα είναι ο δισδιάστατος
 * πίνακας. Ουσιαστικά, ένας δισδιάστατος πίνακας είναι ένας 
 * πίνακας που αποτελείται από μονοδιάστατους πίνακες.    
 */
       
    int i, j, A[9], B[3][3], sum=0;
    
/* 
 * ο πίνακας Α ειναι μονοδιάστατος Πίνακας 9 στοιχείων και ο Β είναι 
 * δισδιάστατος πίνακας 3 x 3 στοιχείων. Αρχικά το προγραμμα διαβάζει
 * 9 αριθμούς και τους καταχωρεί στο μονοδιάστατο πίνακα Α
 */
    
    for (i = 0; i < 9; i++) {
        //printf("dose arithmo : ");
        //scanf("%d",&A[i]);
        A[i]=i+1;   //αυτόματη καταχώρηση των αριθμών 1-9 για λόγους συντομίας
        }

k=A; // Ο δείκτης k δείχνει στο πρώτο στοιχείο του πίνακα Α

/* 
 * Στην συνέχεια αντιγράφει τα στοιχεία του πίνακα Α σε έναν πίνακα Β[3,3]
 * γραμμή πρός γραμμή (δηλαδή τα πρώτα 3 στοιχεία του πίνακα Α θα καταχωρηθούν 
 * στην 1η γραμμή του πίνακα Β, τα επόμενα 3 στην 2η γραμμή, κοκ.)
 */
        printf("Eisagogi sto pinaka B[3][3] me xrisi pointer\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                B[i][j] = *k++; // ισοδύναμο με B[i][j] = A[i * 3 + j];
                printf(" %d",B[i][j]);
                }
                printf("\n");
        }
        printf("Periexomena pinaka B - me xrisi pointer\n");
        k=B; // Ο δείκτης k δείχνει στο πρώτο στοιχείο του πίνακα Β
             // Επειδή είναι πίνακας δυο διαστάσεων, παράγεται ένα warning
             // όπως είδαμε και στη προηγούμενη άσκηση (τέταρτο παράδειγμα)
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) 
                   printf(" %d",*k++);
            printf("\n");
        }
        
/* Πολλές φορές βέβαια, είναι πιο κατάλληλη η χρήση των δεικτών θέσης (indexes)
 * από τη χρήση pointers, π.χ. όταν ενδιαφερόμαστε για τις πληροφορίες θέσης
 * (γραμμή, στήλη) ενός πίνακα δυο διαστάσεων.      
 * Ακολουθεί ο υπολογίσμος και η εμφάνιση του άθροισματος των περιφερειακών 
 * στοιχείων του πίνακα (δηλαδή των στοιχείων της 1ης γραμμής, της 3ης στήλης, 
 * της 3ης γραμμής και της 1ης στήλης)
 */        
        for (i = 0; i < 3; i++)
             sum += B[0][i] + B[2][i] + B[i][2] + B[i][0];
        sum = sum - B[0][0] - B[2][2] - B[0][2] - B[2][0];
/* Τα στοιχεία στις 4 γωνίες του πίνακα έχουν προστεθεί 2 φορές,
 * και πρέπει να αφαιρεθούν. 
*/     
        printf("To athroisma twn periferiakon stoixeiwn einai: %d\n\n",sum);
        
system("pause");
}
