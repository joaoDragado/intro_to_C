/************************************************************
* ΠΛΗ10
* Εισαγωγή στη γλώσσα προγραμματισμού C.
* 
* 6o Αρχείο: 06_strings.c
*
* Αυτό είναι το έκτο πρόγραμμα προς επίδειξη. Ζητούμενο να
* κατανοηθούν βασικά θέματα διαχείρισης αλφαριθμητικών.
* Στο πρόγραμμα δείχνουμε αναλυτικά:
* - Συναρτήσεις διαχείρισης strings
* - Τα strings ως πίνακες χαρακτήρων
* - Συγκρίσεις και αναζήτηση strings()
*
 ************************************************************/

#include <stdio.h>
#include <string.h>
/* Το αρχείο string.h περιέχει όλες τις δηλώσεις των συναρτήσεων διαχείρισης strings */

char name[100] = "Aristos";

/*
 * Ένα string είναι στην πραγματικότητα μια ακολουθία από χαρακτήρες που τερματίζεται με το
 * μηδενικό χαρακτήρα '\0'.
 * Έτσι η παραπάνω δήλωση συμπεριλαμβάνει ουσιαστικά 8 χαρακτήρες, έναν περισσότερο από το μήκος του string.
 */

char *p;
char c;

main()
{
   /* To string εκτυπώνεται από την printf χρησιμοποιώντας το σύμβολο %s.
	* To μήκος του το επιστρέφει η συνάρτηση strlen().
	*/
	printf("Name: %s has size %d\n",name, strlen(name));
	c = getchar();
	/* H συνάρτηση strcat ενώνει δύο strings προσθέτοντας το δεύτερο στο τέλος του πρώτου */
	strcat(name,"Papadopoulos");

	printf("Name: %s has size %d\n",name, strlen(name));
	c = getchar();
	/* H συνάρτηση strcpy αντιγράφει το δεύτερο string στο πρώτο */
	strcpy(name, "Nikiforos");

	printf("Name: %s has size %d\n",name, strlen(name));
	c = getchar();
	
	/* Τα strings δεν παύουν να είναι πίνακες χαρακτήρων. Αυτό σημαίνει ότι μπορούμε
	 * να διαχειριστούμε κάθε χαρακτήρα ξεχωριστά. Δείτε τι συμβαίνει όταν αλλάξουμε την πρώτη
	 * θέση του πίνακα .....
	 */
	name[0]='M';

	printf("Name: %s has size %d\n",name, strlen(name));
	c = getchar();
	/* Επίσης, το string τερματίζεται όταν βρεθεί μηδενικός χαρακτήρας. Ας προσθέσουμε έναν στην θέση
	 * 6 του πίνακα και ας δούμε το αποτέλεσμα.
	 */
	name[5] = '\0';
	printf("Name: %s has size %d\n",name, strlen(name));
	c = getchar();
	/* Μπορούμε ακόμα να χρησιμοποιήσουμε την ιδιότητα της ισοδυναμίας πίνακα με δείκτη και να
	 * προσπελάσουμε ένα μέρος του string...
	 */
	strcpy(name+3,"os");

	printf("Name: %s has size %d\n",name, strlen(name));
	c = getchar();
	/* Εκτός από την scanf, μπορούμε να διαβάσουμε ένα string από το πληκτρολόγιο με τη συνάρτηση
	 * gets()
	 */
	printf("Type your name: ");
	p=name;
	p=gets(p);

	printf("\nYour name is %s and has size %d\n",p, strlen(p));
	c = getchar();
	/* Η σύγκριση δύο string γίνεται με τη συνάρτηση strcmp. H συνάρτηση αυτή συγκρίνει τα δύο αλφαριθμητικά
	 * χαρακτήρα προς χαρακτήρα και επιστρέφει θετικό αριθμό αν το πρώτο είναι μεγαλύτερο από το δεύτερο,
	 * αρνητικό αριθμό αν το δεύτερο είναι μεγαλύτερο από το πρώτο και 0 αν είναι ίδια.
	 * Η εντολή if(!strcmp(....)) είναι η πλέον χαρακτηριστική για τη σύγκριση strings σε C.
	 */
	if(!strcmp(name,"Barack H. Obama"))
			printf("Oh, you are the president of the United States of America!\n");
	else
			printf("You are NOT the president of the United States of America!\n");
	c = getchar();
	/* Η strcmp συγκρίνει τα αλφαριθμητικά σε όλο το μήκος τους. Πολλές φορές αυτό που μας ενδιαφέρει είναι
	 * αν δύο strings έχουν κοινή αρχή. H συνάρτηση strncmp συγκρίνει τους n πρώτους χαρακτήρες των δύο strings
	 * και επιστρέφει τα αντίστοιχα αποτελέσματα με την strcmp
	 */
	if(!strncmp(name,"Kostas",6))
		printf("Your first name is Kostas! \n");
	else
		printf("Your first name is NOT Kostas! \n");
	c = getchar();
	/* Τέλος, πολλές φορές θέλουμε να βρούμε αν ένα string εμπεριέχεται σε ένα άλλο string. Η συνάρτηση
	 * strstr() μας επιστρέφει δείκτη στη θέση της πρώτης εμφάνησης ενος string μέσα σε ένα άλλο string.
	 * Πώς θα βρούμε σε ποιά θέση του αρχικού string εμφανίζεται το δεύτερο? Καθώς και η name αλλά και η
	 * p είναι δείκτες, δηλαδή θέσεις μνήμης, μπορούμε να τις αφαιρέσουμε. Η διαφορά τους αντιστοιχεί στην
	 * απόσταση σε bytes μεταξύ των δύο δεικτών και άρα στην θέση του δεύτερου string στο πρώτο.
	 */
	if(p=strstr(name,"ost"))
		printf("\"ost\" occurs at position %d of the input string\n",	p-name);
	else
		printf("\"ost\" does not occur in the input string\n");
getchar();
}


