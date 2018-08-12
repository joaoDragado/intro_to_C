/************************************************************
 * ΠΛΗ10 
 * Εισαγωγή στη γλώσσα προγραμματισμού C.
 * 
 * 2o Αρχείο: 02_types.c
 *
 * Αυτό είναι το δεύτερο πρόγραμμα προς επίδειξη. Ζητούμενο να 
 * κατανοηθούν οι διάφοροι βασικοί τύποι της C ως προς το 
 * μέγεθος και τη συμπεριφορά τους. Αναλυτικά θα παρουσιαστούν:
 * - Η δήλωση πίνακα
 * - Η χρήση της συνάρτησης sizeof()
 * - Η διαφοροποίηση  signed - unsigned
 * - Η χρήση της συνάρτησης getchar()
 * - Ο τελεστής ~ 
 * - Η δεκαεξαδική αναπαράσταση
 * - Τα προβλήματα υπερχείλισης σε προσημασμένες και μη 
 *    προσημασμένες μεταβλητές
 * - Τα προβλήματα ακρίβειας στην αναπαράσταση floating point 
 *   αριθμών και τις συνέπειές τους
 ************************************************************/
 
#include <stdio.h>

char a;

main()
{
	char c;
	unsigned char uc;
	short s;
	unsigned short us;
	int i;
	unsigned int ui;
	long l;
	unsigned long ul;
	float f;
	double d;
	int array[10];

	printf("sizeof char: %d\n",sizeof(char));
	printf("sizeof unsigned char: %d\n",sizeof(unsigned char));

	a = getchar();
	printf("sizeof short: %d\n",sizeof(short));
	printf("sizeof unsigned short: %d\n",sizeof(unsigned short));
	a = getchar();
	printf("sizeof int: %d\n",sizeof(int));
	printf("sizeof unsigned int: %d\n",sizeof(unsigned int));
	a = getchar();
	printf("sizeof long: %d\n",sizeof(long));
	printf("sizeof unsigned long: %d\n",sizeof(unsigned long));
	a = getchar();
	printf("sizeof float: %d\n",sizeof(float));
	a = getchar();
	printf("sizeof double: %d\n",sizeof(double));
	a = getchar();
	printf("sizeof int array[10]: %d\n",sizeof(array));
	a = getchar();

	/* Πως θα βρούμε τον μεγαλύτερο δυνατό αριθμό τύπου char? Λογικά, 
	 * καθώς αποτελείται από ένα byte και σε αυτό υπάρχουν 8 bits, η μέγιστη τιμή 
	 * προκύπτει αν σε όλα αυτά τα bits βάλουμε 1. Ο αριθμός που προκύπτει 
	 * εύκολα μπορείτε να δείτε ότι είναι ο 255. 
	 * Αντί να ψάχνουμε να θυμηθούμε πόσα bytes έχει ο κάθε τύπος μεταβλητής 
	 * κάνουμε κάτι που καλύπτει όλους τους τύπους: Ο τελεστής ~ είναι ο τελεστής του 
	 * συμπληρώματος ως προς 1. ʼρα το ~0 είναι ο αριθμός με όλα τα bits 1, ανεξάρτητα 
	 * από το μέγεθος. 
	 */
	c = ~0;
	printf("\nmax char: %d\n", c);
	a = getchar();
	/* 
    * Εναλλακτικά της system("pause") για να προλαβαίνουμε να διαβάσουμε τι γράφει το παράθυρο αποτελεσμάτων.
    */

	/* Γιατί -1? Η μεταβλητή c είναι προσημασμένη, οπότε αν το πρώτο bit είναι 1 
	 * το σύστημα θεωρεί ότι ο αριθμός είναι αρνητικός! Για την αναπαράσταση 
	 * των αρνητικών αριθμών στον υπολογιστή χρησιμοποιείται συμπλήρωμα ως προς 2 
	 * και εύκολα μπορείτε να επιβεβαιώσετε ότι η αναπαράσταση με 8 bits του -1 σε 
	 * συμπλήρωμα ως προς δύο είναι 11111111 <2> .
	 * Ποιά όμως είναι στην περίπτωση αυτή η μεγαλύτερη τιμή που μπορεί να πάρει η c? 
	 * προφανώς η 01111111 (το πρώτο bit 0 για να είναι θετικός). Πώς την αναθέτουμε?
	 * Έτσι:
	 */
	c = ~0x80;
	printf("\nmax char: %d\n", c);

	a = getchar();
	
	/* Τώρα δουλεύει. Σύμφωνα όμως με τα παραπάνω, αν δεν έχουμε προσημασμένη 
	 * μεταβλητή, θα πρέπει να μπορούμε να φτάσουμε μέχρι και 255. Για να δούμε:
	 */

	uc = ~0;
	printf("\nmax unsigned char: %d\n", uc);

	a = getchar();

	/* Ας δούμε τις αντίστοιχες παρατηρήσεις στους υπόλοιπους τύπους....
	 */
	us = ~0;
	printf("\nmax unsigned short: %d\n", us);
	a = getchar();

	s = ~0x8000;
	printf("\nmax short: %d\n", s);
	a = getchar();

	ui = ~0;
	printf("\nmax unsigned int: %d\n", ui);
	a = getchar();
	printf("\nmax unsigned int: %u\n", ui);
	a = getchar();

	/* Όμως τί θα γίνει αν στον μέγιστο μη προσημασμένο αριθμό προσθέσουμε 1? 
	 * Ποιός αριθμός προκύπτει? 
	 */
	printf("\nmax unsigned int + 1: %u\n", ui+1);
	a = getchar();

    	/* Προφανώς το 0, καθώς δεν υπάρχει χώρος για να κρατήσουμε κάπου το 1 που 
	 * προκύπτει στο bit 33. Αντίστοιχα και για signed int */

	i = ~0x80000000;
	printf("\nmax int: %d\n", i);
	a = getchar();

	printf("\nmax int +1: %d\n",i+1);
	a = getchar();

	ul = ~0;
	printf("\nmax unsigned long: %u\n", ul);
	a = getchar();
	l = ~0x80000000;
	printf("\nmax long: %ld\n", l);
	a = getchar();

	f = ~0;
	printf("\nfloat: %f\n", f);
	a = getchar();
	d = ~0;
	printf("\nmax double: %f\n", d);
	a = getchar();

	/* Για να δούμε όμως τι ακρίβεια μπορούμε να έχουμε χρησιμοποιώντας μεταβλητές τύπου 
	 * float...
	 */
	f = 854309.123;
	printf("\nO arithmos f = 854309.123 (float), emfanizetai (lanthasmena) os: %f\n", f);
	a = getchar();

	/* Γιατί εμφανίζεται .125 και όχι .123? Το πρόβλημα είναι στον αριθμό των bits που 
	 * διατίθενται στην αναπαράσταση του αριθμού. Προφανώς το σύστημα αφιερώνει όσα bits 
	 * χρειάζονται για την αναπαράσταση του ακέραιου και όσα περισσεύουν για το δεκαδικό 
	 * μέρος. Προφανώς στη συγκεκριμένη περίπτωση περισσεύουν 3 bits καθώς ο αριθμός 
	 * .001 <2> είναι ακριβώς 1/8 = .125.  
	 * ʼν όμως είναι έτσι, τότε το πρόβλημα είναι πρόβλημα επάρκειας bits. Στην περίπτωση 
	 * αυτή αν χρησιμοποιούσαμε μεταβλητή τύπου double δεν θα είχαμε τέτοια προβλήματα! 
	 * Για να δούμε....
	 */

	d = 854309.123;
	printf("\nO arithmos d = 854309.123 (double), emfanizetai (sosta) os: %f\n", d);
	a = getchar();

	/* Όντως, αυτή τη φορά εκτυπώθηκε σωστά! Προσοχή όμως, η συγκεκριμένη συμπεριφορά 
	 * μπορεί να παρουσιάσει διάφορα παράδοξα όπως το παρακάτω: 
	 */

	d = 854309.124;
	
    printf("Ston f exei apodothei mikroteri timi apo ton d\n");
    printf("Omos, logo elleipsis akriveias ston typo float tou f,");
    printf("\n   o f eklamvanetai os megalyteros tou d\n\n");
    
    if(f>d) 
		printf(" 854309.123 > 854309.124\n");
	else
		printf(" 854309.123 < 854309.124\n\n");
	printf("To provlima den tha emfanizotan an f kai d eixan ton idio typo (double)\n\n");	

system ("PAUSE");
}
