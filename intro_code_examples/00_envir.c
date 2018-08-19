/************************************************************
* ΠΛΗ10
* Εισαγωγή στη γλώσσα προγραμματισμού C.
* 
* 9o Αρχείο: 09_envir.c
*
* Αυτό είναι το ένατο πρόγραμμα προς επίδειξη. Το πρόγραμμα 
* παρουσιάζει τον τρόπο αλληλεπίδρασης των προγραμμάτων της C 
* με το λειτουργικό μέσα από τα command line arguments.  
*
 ************************************************************/

#include <stdio.h>

/* Αν και στα μέχρι τώρα προγράμματα καλούσαμε την main χωρίς παραμέτρους, 
 * πάντα το λειτουργικό χρησιμοποιεί τρείς παραμέτρους στην main για να περάσει  
 * χρήσιμες πληροφορίες σχετικά με το σύστημα. 
 * Η πρώτη (argc, από το argument count) είναι ο αριθμός των παραμέτρων με τις οποίες καλείται το 
 * εκτελέσιμο πρόγραμμα. Συνήθως ο αριθμός αυτός είναι 1. Ο πίνακας argv περιέχει 
 * argc strings, το πρώτο από τα οποία είναι το όνομα με το οποίο έγινε η κλήση
 * του προγράμματος. O πίνακας envp περιέχει έναν αριθμό από strings που δίνουν τιμές σε αντίστοιχες 
 * μεταβλητές του συστήματος. Τερματίζει με NULL δείκτη, και για τον λόγο αυτό ο 
 * έλεγχος στο παρακάτω πρόγραμμα είναι while(envp[i]!=0)
 */
main(int argc, char * argv[],char * envp[])
{
	int i = 0,k;

    printf("Apo to periexomeno tis 1is parametrou (akeraios argc)\n  Plithos parametron ektelesis: %d\n", argc);
	printf("Apo to periexomeno tis 2is parametrou (pinakas strings argv[])\n");
	printf("  Parametroi ektelesis:\n");
	
    printf("  1h parametros ektelesis - yparxei panta (the name of this executable)\n  is %s\n", argv[0]);
    
    for (k=1;k<argc;k++)
        printf("  H %dh parametros ektelesis is %s\n", k+1, argv[k]);
    	/* Για να μπορέσετε να δείτε πώς εμφανίζονται οι παράμετροι εκτέλεσης
         * που μπορεί να έχει ένα πρόγραμμα C, βάλτε δυο-τρια strings χωρισμένα 
	     * με κενό μεταξύ τους, μέσω του μενού Εκτέλεση --> Παράμετροι...
        */
    
	printf("\nApo to periexomeno tis 3is parametrou (pinakas strings envp[])\n");
	printf("  Metavlites systimatos:\n");
    while(envp[i] != 0)
		printf("  Environment variable: %s\n", envp[i++]);
system ("pause");
}
