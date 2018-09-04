/****************************************************************
 * ΠΛΗ10 
 * Εισαγωγή στη γλώσσα προγραμματισμού C.
 * 
 * 16o Αρχείο: 16_switch.c
 * 
 * Αυτό είναι το δέκατο έκτο πρόγραμμα προς επίδειξη.
 * Ζητούμενο της άσκησης είναι να κατανοηθούν βασικά θέματα χρήσης
 * των δομών επιλογής και επανάληψης. Κυρίως της δομής επιλογής
 * switch και της χρήσης της για την δημιουργία menu επιλογών.
 * ʼλλα στοιχεία: έλεγχος κωδικού σύνδεσης 
 * και αμυντικός προγραμματισμός
 *
 * Το πρόγραμμα προσομοιώνει ένα τραπεζικό σύστημα 
 ****************************************************************/


#include<stdio.h>
#include<string.h>
/* Το αρχείο string.h περιέχει όλες τις δηλώσεις των συναρτήσεων διαχείρισης strings */

main(){
	char password[]="kodikos",cpswrd[10];
	float euro=2000.0,amount;
    /* Ο προκαθορισμένος κωδικός είναι το kodikos 
    * και το αρχικό υπόλοιπο (μεταβλητή euro) είναι 2.000 euros  */
    
    
	int i=1, choice;

	do {
        printf("Dwse ton kwdiko toy systhmatos (%dh apo 3 prospatheies):",i++);
		gets(cpswrd);
	}
    while(strcmp(cpswrd,password)!=0 && i<4);

   /* 
   * Ο χρήστης έχει τρεις προσπάθεις για να πληκτρολογήσει τον σωστό κωδικό
   * Μετα τις τρείς προσπάθειες και αν δεν είναι σωστός ο κωδικός θα εκτελεστεί
   * η else της ακόλουθης if
   */
	if(strcmp(cpswrd,password)==0){
		
    do {
    printf("\n\n------------------\n");
    printf("-------Menou------\n");
    printf("1: Katathesi posou\n");
    printf("2: Analipsi posou\n");
    printf("3: Emfanisi ypoloipou\n");
    printf("0: Exit\n");
    printf("Dwse thn epilogh sou:");
    scanf("%d",&choice);

/* 
 * H δομή επιλογής switch χρησιμοποιεί τον επιλογέα choice για να δώσει
 * στον χρήστη την δυνατότητα να περιηγείται στο menu
 */

    switch(choice)
    {
	case 1:
		do{
		printf("Dwse to poso katathesis:");
		scanf("%f",&amount);
		}while(amount<=0);
		/*
		* αμυντικός προγραμματισμός - δεκτοί μόνο οι θετικοί αριθμοί 
		*/

		euro += amount;
		printf("Neo ypoloipo:%.2f\nTelos synallaghs\n",euro);
		break;
	case 2:
		if (euro) {    // Επιτρέπεται Ανάληψη μόνον όταν υπάρχει Υπόλοιπο > 0
          do {
		   printf("Dwse to poso analipsis:");
		   scanf("%f",&amount);
		  }while(amount<=0 || amount>euro);
		  /*
	      * αμυντικός προγραμματισμός - δεκτοί μόνο οι θετικοί αριθμοί 
          * που είναι μικρότεροι του τρέχοντος υπολοίπου 
		  */
          euro -= amount;
		  printf("Neo ypoloipo:%.2f\nTelos synallaghs\n",euro);
       }
	   else printf("********************\nYpoloipo MHDEN - Den epitrepontai Analipseis\n********************");
		break;
	case 3:
		printf("\nYpoloipo synallagis:%.1f\n",euro);
		break;
	case 0:
		printf("Exodos\n");
		break;
	default:
		printf("Lathos epilogi\n");
		break;
	}
	}while(choice);    /* όσο η choice είναι διαφορετική του 0
	                   /* (όλοι οι αριθμοί στη C είναι TRUE εκτός του 0 που είναι FALSE)
                       /* Έτσι, while(choice) είναι ισοδύναμο με while (choice !=0)
                       */
	}
	else
		printf("3 lathos prospatheies!\nExit\n");
    
    system("pause");
}
