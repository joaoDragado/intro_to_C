/************************************************************
* ΠΛΗ10
* Εισαγωγή στη γλώσσα προγραμματισμού C.
* 
* 15o Αρχείο: 15_list_ii.c
*
* Αυτό είναι το δέκατο πέμπτο πρόγραμμα προς επίδειξη. Το πρόγραμμα 
* παρουσιάζει τη δημιουργία και τη διαχείριση μιας δυναμικής
* απλά διασυνδεδεμένης λίστας.  
*
 ************************************************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>


struct node{
	int position;
	char name[30];
    struct node * next;
   };

typedef struct node MY_NODE;

void short_print_node(MY_NODE * mn);
void short_print_list(MY_NODE * list);
void free_list(MY_NODE * list);

MY_NODE * my_list;

main()
{
	int i;
	MY_NODE * pn = NULL; /* θα χρησιμοποιηθεί για ανάθεση νέου κόμβου */
	MY_NODE * last; /* δείχνει στον τελευταίο κόμβο της λίστας */
	char str[100]; /* χρησιμοποιείται για την αποθήκευση των δεδομένων που εισάγει ο χρήστης */

	/* δημιουργία νέου κόμβου */
	pn = (MY_NODE *) malloc(sizeof(MY_NODE));
	if(pn == NULL)
	{
	   printf("Error in malloc\n");
	   exit(1);
	}
	/* γέμισμα τιμών */
	pn->position = 1;
	strcpy(pn->name, "Xara");
    	pn->next = NULL;

	/* σύνδεση με λίστα */
    	my_list = pn;

    	/* δημιουργία νέου κόμβου */
	pn = (MY_NODE *) malloc(sizeof(MY_NODE));
	if(pn == NULL)
	{
	   printf("Error in malloc\n");
	   exit(1);
	}
	/* γέμισμα τιμών */
	pn->position = 2;
	strcpy(pn->name, "George");
    	pn->next = NULL;

	/* σύνδεση στο τέλος της λίστας */
	my_list->next = pn;

	//print_list(my_list);

	short_print_list(my_list);

	/* δημιουργία και πρόσθεση νέων κόμβων στη λίστα */
	/* μέχρι ο χρήστης να δώσει κενό string */
	last = my_list->next;
	i = 3;
	do {
		printf("\nName:");
		gets(str);
		if(str[0] != '\0')
		{
			pn = (MY_NODE *) malloc(sizeof(MY_NODE));
			if(pn == NULL)
			{
			   printf("Error in malloc\n");
			   exit(1);
			}
			/* γέμισμα τιμών */
			pn->position = i;
			strcpy(pn->name, str);
 		    pn->next = NULL;
			/* πρόσθεση νέου κόμβου στο τέλος της λίστας */
			last->next = pn;
			last = last->next;
		}
		i++;
	}while ( str[0] != '\0');

	short_print_list(my_list);

	/* ελευθέρωσε τη μνήμη */
	free_list(my_list);
	system("pause");
}


/****************************************************/
/*	Συνάρτηση: short_print_node					    */
/*  Είσοδος: pointer to Node						*/
/*  Έξοδος: NONE									*/
/*  Λειτουργία:τυπώνει τα δεδομένα του κόμβου		*/
/****************************************************/

void short_print_node(MY_NODE * mn)
{
	printf("%d, %s -> ",mn->position, mn->name);
	if(mn->next == NULL)
		printf("|||\n");
}

/****************************************************/
/*	Συνάρτηση: short_print_list					    */
/*  Είσοδος: pointer to Node						*/
/*  Έξοδος: NONE									*/
/*  Λειτουργία:τυπώνει όλους τους κόμβους της λίστας*/
/****************************************************/

void short_print_list(MY_NODE * list)
{
	printf("\n\n Short List: \n------------------------------------\n");
	while(list != NULL)
	{
		short_print_node(list);
		list = list->next;
	}

}

/*********************************************************/
/*	Συνάρτηση: free_list							     */
/*  Είσοδος: pointer to Node							 */
/*  Έξοδος: NONE									     */
/*  Λειτουργία: ελευθερώνει όλους τους κόμβους της λίστας*/
/*********************************************************/

void free_list(MY_NODE * list)
{
	MY_NODE * next_node;

	printf("\n\n Freeing List: \n");
	while(list != NULL)
	{
		next_node = list->next;
		free(list);
		list = next_node;
		printf("->");
	}

}

