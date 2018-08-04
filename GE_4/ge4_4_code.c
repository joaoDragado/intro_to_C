#include <stdio.h>
#include <stdlib.h>

#define A 3
#define C 19
#define M 15001
#define SEED 27
#define HTSIZE 500

typedef struct node {
    int value;
    int counter;
    struct node *next;
} t_listnode;

typedef struct {
    t_listnode *head;
    t_listnode *tail;
} t_htentry;


/* Δηλώσεις συναρτήσεων */
int insertElement (int x, int counter, t_htentry *ht, int size); /* Εισαγωγή στοιχείου στον πίνακα κατακερματισμού */
int searchElement (int x, t_htentry *ht, int size); /* Αναζήτηση στοιχείου στον πίνακα κατακερματισμού */
int generate(int a, int c, int m, int x); /* Γεννήτρια ψευδοτυχαίων αριθμών */
int findPeriod(int a, int c, int m, int x);  /* Εύρεση της περιόδου της ψευδοτυχαίας ακολουθίας αριθμών */

int main() {
     
    int period;
    
    period = findPeriod(A, C, M, SEED); /* Κάλεσε τη συνάρτηση υπολογισμού περιόδου. */
    
    printf("The period of the sequence is: %d\n", period);
    
    return 0;
}


/* Εισαγωγή στοιχείου στον πίνακα κατακερματισμού. Η συνάρτηση δέχεται ως ορίσματα το στοιχείο x που εισάγεται, τη σειρά εισαγωγής counter,	τον πίνακα κατακερματισμού ht και το μέγεθος size του πίνακα */
 
int insertElement (int x, int counter, t_htentry *ht, int size){
    int ht_Index;
    // using the hash function
    ht_Index = x % HTSIZE;
    
    //build a node to host the number
    t_listnode *hashNode=malloc(sizeof(t_listnode));
    if(NULL == hashNode)
    {
        printf("\n Memory Allocation of hash Node failed \n");
        return 0;
    }
    //populate the node's fields
    hashNode->value = x;
    hashNode->counter = counter;
    hashNode->next = NULL;
    /*position the node to the linked list*/
    /* if position is empty, the node populates both head and tail pointers*/
    if ((ht + ht_Index)->head ==NULL)
    {
        (ht + ht_Index)->head = (ht + ht_Index)->tail = hashNode;
    }
    /*if there is a node, have its *next point to the new node, and set new node as tail*/
    else 
    {
        (ht + ht_Index)->tail->next = hashNode;
        (ht + ht_Index)->tail = hashNode;
        
    }    

return 1;
}


/* Αναζήτηση στοιχείου στον πίνακα κατακερματισμού. Η συνάρτηση δέχεται ως ορίσματα τον αριθμό x που αναζητούμε τον πίνακα κατακερματισμού ht και το μέγεθος size του πίνακα. Επιστρέφει τη σειρά εισαγωγής του στοιχείου ή 0 αν το στοιχείο δε βρεθεί.	*/

int searchElement (int x, t_htentry *ht, int size) {
    
     int ht_Index;
    // using the hash function
    ht_Index = x % HTSIZE;
    
    t_listnode *searchNode = (ht + ht_Index)->head;
    /*Search is pointless if there are no nodes in that index.*/
    if (searchNode==NULL) return 0;
    /*traverse the list in ht[ht_Index] in search of the number*/
    while (searchNode->next!=NULL)
    {
        if ((searchNode->value)==x )
        {
           return searchNode->counter;     
        }
        else searchNode = searchNode->next;
    }
/*the code will get here if the search was negative.*/    
return 0;
}


/* Παραγωγή ψευδοτυχαίου αριθμού.  Η συνάρτηση δέχεται ως ορίσματα τις παραμέτρους a, c, m της γεννήτριας 	
 και τον προηγούμενο αριθμό x. Επιστρέφει τον επόμενο ψευδοτυχαίο αριθμό.  */
 
int generate(int a, int c, int m, int x) {
    
    int nextRand=0;
    nextRand = (a*x + c)%m ;
    return nextRand;
}


/* Εύρεση της περιόδου μίας ακολουθίας ψευδοτυχαίων αριθμών. Η συνάρτηση δέχεται ως ορίσματα τις παραμέτρους a, c, m της γεννήτριας  και τον αριθμό x με τον οποίο τροφοδοτείται αρχικά η γεννήτρια και επιστρέφει την περίοδο της ακολουθίας. */

int findPeriod(int a, int c, int m, int x) {
    int i, period, check;
    /*allocate memory for the hashtable and initialize each of the element's pointers*/
    t_htentry *hashTable = malloc(HTSIZE * sizeof(t_htentry));
    if(NULL == hashTable)
    {
        printf("\n Memory Allocation of hash Table failed \n");
        return 0;
    }
    for (i = 0; i < HTSIZE; i++)
    {
        (hashTable+i)->head=(hashTable+i)->tail=NULL;
    }
    /*initialize random no to SEED*/
    int randNo = SEED;
    int counter =0; //initialize counter
    
    for (i = 0; i < M; i++)
    {
        //generate random number
        randNo = generate(a,c,m,randNo);
        /*check to see if an occurrence of the number exists in the hash table*/
        check = searchElement(randNo,hashTable,HTSIZE);
        /*if prior occurrence exists, subtract from counter to get the period, and return the value*/
        if (check)
        {
            period = counter - check;
            return period;    
        }
        /*otherwise populate the hash table and icrement the counter value*/
        else counter +=insertElement(randNo, counter, hashTable, HTSIZE);
            
    }
    
return 0;    
}
