#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10          /* μέγεθος ονόματος */
#define NUM_PER_LINE 6   /* πλήθος ονομάτων ανά γραμμή */

typedef struct node
{
   char name[SIZE];   /* SIZE-1 χαρακτήρες και το '\0' */
   struct node * next;
} CListNode;

/* Ακολουθούν τα πρότυπα των συναρτήσεων (function prototypes) */
int read_positive_integer(char *msg);
void go_to_pause();
void get_name(char *a);
CListNode *insert_at_end(CListNode *end_ptr, char a[SIZE]);
CListNode *initialize_list(int n);
CListNode *delete_next_node(CListNode *end_ptr, CListNode *p);
void print_list(CListNode *end_ptr);
CListNode *Select(CListNode *end_ptr, int k);


int main()
{
   int num, k;
   CListNode *list_end_ptr, *ptr;

   printf("Selecting a Person from a Set of Persons\n");

   /* διάβασε πλήθος ατόμων */
   num = read_positive_integer("number of persons");

   /* αρχικοποίησε την κυκλική λίστα και τύπωσέ την */
   list_end_ptr = initialize_list(num);
   print_list(list_end_ptr);

   /* διάβασε πλήθος ατόμων που μετράμε σε κάθε επανάληψη */
   k = read_positive_integer("number of persons to skip");

   /* επίλεξε άτομο εφαρμόζοντας τη μέθοδο που περιγράφηκε */
   ptr = Select(list_end_ptr, k);
       
   printf("\nThe person Selected is: %s\n", ptr->name);
   
   printf("\nEnd of program.\n");
   go_to_pause();
   return(0);
}


/* Η συνάρτηση δέχεται ως όρισμα έναν πίνακα χαρακτήρων 	που περιέχει τι πρέπει να διαβασθεί για να τον τυπώσει 
σε σχετικό μήνυμα, διαβάζει έναν θετικό αριθμό και τον επιστρέφει. */
int read_positive_integer(char *msg)
{
   int h;
   
   /* διάβαζε όσο δεν δίδεται θετικός αριθμός */
   do
   {
      /* τύπωσε σχετικό μήνυμα */
      printf("\nType the %s: ", msg);
      
      scanf("%d", &h);
      if (h <= 0)
      {  /* δεν δόθηκε θετικός αριθμός */
         printf("The %s must be positive.\n", msg);
      }
   } while (h <= 0);

   return(h);
}


/* Η συνάρτηση σταματά την εκτέλεση (όπως με: system("PAUSE");) */
void go_to_pause()
{
   char ch;

   /* αρχικά, αγνόησε χαρακτήρες έως το τέλος της γραμμής  */
   while (scanf("%c",&ch) != EOF && ch != '\n')
      ;   /* επανάλαβε την ανάγνωση και τον έλεγχο */
   printf("\nPress ENTER to continue . . . "); /* μήνυμα */
   getchar();
}

char a[SIZE];
/* Η συνάρτηση διαβάζει μια ακολουθία SIZE-1 χαρακτήρων και   */
/* τους αποθηκεύει στον πίνακα a.                             */
void get_name(char *a)
{
   char format[10];

   sprintf(format, "%%%ds", SIZE-1);
   scanf(format, a);
}

/* Η συνάρτηση δέχεται ως ορίσματα δείκτη end_ptr στον τελευταίο κόμβο μιας κυκλικής απλά διασυνδεδεμένης λίστας  
με κόμβους τύπου CListNode και ένα δείκτη σε έναν πίνακα SIZE χαρακτήρων και εισάγει στο τέλος της λίστας έναν κόμβο 
αποθηκεύοντας το περιεχόμενο του πίνακα στο πεδίο name. 
Η συνάρτηση επιστρέφει δείκτη στον τελευταίο κόμβο της λίστας που προκύπτει. */

CListNode *insert_at_end(CListNode *end_ptr, char *a)
{
    CListNode *new;
        
    if (end_ptr==NULL) /*if list is empty*/
    {
        /*allocate memory for node*/
        new=(CListNode *)malloc(sizeof(CListNode));
        /*copy string to node's name field*/
        strcpy(new->name, a);
        /*since list has only 1 node, it should point to itself.*/
        new->next = new;
    } else
    {
        new=(CListNode *)malloc(sizeof(CListNode));
        strcpy(new->name, a);
        /*node points to the start of the list*/
        new->next = end_ptr->next;
        /*place node to the end of list*/
        end_ptr->next = new;
    }
    return new ;
}

/* Η συνάρτηση δέχεται ως όρισμα το πλήθος n των ατόμων που συμμετέχουν στην επιλογή, αρχικοποιεί την κυκλική απλά       
 διασυνδεδεμένη λίστα εισάγοντας για κάθε άτομο έναν κόμβο στο τέλος της τρέχουσας λίστας και επιστρέφει δείκτη στον   
 τελευταίο κόμβο της τελικής λίστας. */
 
CListNode *initialize_list(int n)
{
    CListNode *tail;
    tail=NULL;
    while (n)
    {
        printf("Enter Person's Name (max. 9 characters): ");
        get_name(a);
        tail = insert_at_end(tail, a);
        n--;
    }
   
    return tail;
}

/* Η συνάρτηση δέχεται ως ορίσματα δείκτη end_ptr στον τελευταίο κόμβο μιας κυκλικής απλά διασυνδεδεμένης λίστας με 
κόμβους τύπου CListNode και δείκτη p σε έναν κόμβο της λίστας διαγράφει τον κόμβο που βρίσκεται αμέσως μετά από αυτόν που δείχνεται από τον p και αποδεσμεύει τον χώρο που καταλαμβάνει. Η συνάρτηση επιστρέφει δείκτη στον τελευταίο κόμβο της λίστας.*/

CListNode *delete_next_node(CListNode *end_ptr, CListNode *p)
{

    CListNode *current, *last, *temp;
    last = end_ptr; 
    current = last->next; //current points to first node of list.
    
    if (last==NULL) printf("List is empty.\n");
    /* traverse list in search of p */
    while (last!=current && p!=current) {
            current = current->next;
    }
    /* move 1 node after p*/
    temp=current->next;
    printf("%s removed from the list\n",temp->name);
    /*remove node from the list*/
    current->next=temp->next;
    /*delete node freeing its memory*/
    free(temp); 
/*returns pointer to the node after the target, for the next iteration*/    
return current->next;
}
    
/* H συνάρτηση δέχεται ως όρισμα δείκτη end_ptr στον τελευταίο κόμβο μιας κυκλικής απλά διασυνδεδεμένης λίστας με κόμβους τύπου CListNode και εμφανίζει τα περιεχόμενα των πεδίων name των κόμβων της λίστας από τον 1ο έως τον τελευταίο κόμβο της. Σε κάθε γραμμή (εκτός πιθανόν της τελευταίας) εμφανίζονται NUM_PER_LINE ονόματα τα οποία είναι στοιχισμένα. 	
Εάν η λίστα είναι κενή, εμφανίζεται αντίστοιχο μήνυμα λάθους. */

void print_list(CListNode *end_ptr)
{
    CListNode *last, *current;
    int i=1; 
    last = end_ptr;
    if (last==NULL) printf("List is empty.");
    else
    {
        /*current points to start of list*/
        current = last->next;
        /*traverse list nodes printing their names*/
        while (current != last)
        {
            printf("%s\t", current->name);
            /*use modulus to delimit no of nodes printed in each line */
            if (!(i%NUM_PER_LINE)) printf("\n");
            i++;
            current = current->next;
        }
        printf("%s\t", last->name);
    }
}

/* Η συνάρτηση δέχεται ως ορίσματα δείκτη end_ptr στον τελευταίο κόμβο μιας κυκλικής απλά διασυνδεδεμένης λίστας με  
κόμβους τύπου CListNode και θετικό ακέραιο k. Εφόσον η λίστα έχει παραπάνω από έναν κόμβο, διαγράφει       
επαναληπτικά τον k-οστό κόμβο της τρέχουσας λίστας τυπώνοντας τα περιεχόμενά της μετά από κάθε διαγραφή.                 	
Η συνάρτηση επιστρέφει δείκτη στο μοναδικό κόμβο που απομένει στη λίστα.*/

CListNode *Select(CListNode *end_ptr, int k)
{
    int i;
    CListNode *current, *last;
    last = end_ptr;
    /*current points to start of list*/
    current = last->next;
    if (last==NULL) printf("List is empty.\n");
    /*notify if only 1 node in list*/
    else if (last==current){
       printf("Cannot perform Operation. List contains only 1 element.\n"); 
    }
    else
    {
        /*keep performing the code below until only 1 node remains*/
        while (last!=current)
        {
        /*move to the k node*/
            i=k;
        while (i)
        {
            current = current->next;
            i--;
        }
        /*delete the node and return the node it pointed to.*/
        last = delete_next_node(last, current);
        }
    }
    /*return the 1 remaining node*/
    return last;    
}
