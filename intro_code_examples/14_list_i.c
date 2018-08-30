/************************************************************
* ΠΛΗ10
* Εισαγωγή στη γλώσσα προγραμματισμού C.
* 
* 14o Αρχείο: 14_list_i.c
*
* Αυτό είναι το δέκατο τέταρτο πρόγραμμα προς επίδειξη. Το πρόγραμμα 
* παρουσιάζει βασικά θέματα δήλωσης και χρήσης δομών (structs) 
* Επίσης χρησιμοποιείται η συνάρτηση malloc()
*
 ************************************************************/

#include <stdio.h>
#include <string.h>
/* Για να χρησιμοποιήσουμε την malloc στα προγράμματά μας πρέπει να 
 * συμπεριλάβουμε την παρακάτω δήλωση:
 */
#include <malloc.h>


struct node{
	int position;
	char name[30];
    struct node * next;
   };

typedef struct node MY_NODE;

void print_node(MY_NODE * mn);

MY_NODE * my_list;

main()
{
	MY_NODE n;
	MY_NODE * pn = NULL;

	/* επίδειξη για το πως χειριζόμαστε την δομή*/
	n.position = 100;
	strcpy(n.name,"Kostas_static");
	n.next = NULL;

	print_node(&n);

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

	/* σύνδεση με την λίστα*/
	my_list = pn;

	printf("\n\n my list\n");
    print_node(my_list);

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

    printf("\n\n my list\n");
    
    /* 1ος κόμβος */
    print_node(my_list);
    
    /* ο επόμενος κόμβος είναι ο τελευταίος της λίστας */
	print_node(my_list->next);

system("pause");
}

void print_node(MY_NODE * mn)
{
	printf(">>>>>>>>>>>>>>>>>>>>>\n");
	printf("\nNode %d : \tName: %s \t",mn->position, mn->name);
	if(mn->next)
		printf("\n");
	else
		printf("||| (last node in list)\n");
}
