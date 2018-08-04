#include <stdio.h>
#include <stdlib.h>


/* Δήλωση των συναρτήσεων */
void loadMatrix (int **F, int size);
int findFriends (int **F, int size, int user);
int commonFriends (int **F, int size, int user1, int user2);
void sortUsers (int **F, int size, int *S);

int main() {

    int **matrixF; /* ο πίνακας με τη σχέση φιλίας */
    int *matrixS;  /* ο πίνακας με το πλήθος των φίλων ανά χρήστη */
    int num_users; /* το πλήθος των χρηστών */    
    int i, j;
    

    /* Διάβασε το πλήθος των χρηστών */
    printf("Give number of users: ");
    scanf("%d", &num_users);
    
    /* Δέσμευσε μνήμη για την αποθήκευση του πίνακα φιλίας. */
    matrixF = (int **) malloc(num_users * sizeof(int *));
    if (!matrixF) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    for (i = 0; i < num_users; ++i) {
        matrixF[i] = (int *) malloc(num_users * sizeof(int));
        if (!matrixF[i]) {
          printf("Memory allocation error!\n");
          exit(1);
        }
    }
    
    loadMatrix(matrixF, num_users);
              
    /* Έλεγχος για πλήθος φίλων του κάθε χρήστη. */
    for (i=0; i<num_users; ++i) {
        printf("Number of friends of user %d: %d\n", i+1, findFriends(matrixF, num_users, i));
    }
    
    /* Έλεγχος για πλήθος κοινών φίλων */
    for (i=0; i<num_users; ++i) {
        for (j=0; j<i; ++j) {    
            printf("Number of common friends of %d and %d: %d\n", i, j, commonFriends(matrixF, num_users, i, j));
        }
    }
    
    matrixS = (int *)malloc(num_users * sizeof(int));
    if (!matrixS) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    sortUsers(matrixF, num_users, matrixS);

    /* Τύπωσε το πλήθος των φίλων σε μη φθίνουσα διάταξη. */
    for (i=0; i<num_users; ++i) {
      printf("%d friends.\n", matrixS[i]);
    }

    return 0;
}

/* Η συνάρτηση δέχεται ως ορίσματα τον πίνακα F και έναν ακέραιο αριθμό size που δηλώνει το πλήθος των χρηστών. Στη συνέχεια, τυπώνει στην οθόνη όλα τα δυνατά ζεύγη χρηστών και για το καθένα ζητά από το χρήστη  να δηλώσει εάν οι δύο χρήστες είναι φίλοι ή όχι, και ενημερώνει κατάλληλα τον πίνακα */

void loadMatrix (int **F, int size) {
    
    int i,j; // temp loop variables
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            while ( i!=j && i>j) // defensive mechanism for out-of-bound values
            {
                printf("Enter '1' if  users %d and %d friends, '0' otherwise : ",i+1, j+1 );
                scanf("%d",&F[i][j]);
                //printf("%d",F[i][j]);
                while (!(F[i][j]==0 || F[i][j]==1))
                {
                    printf("Accepted values are '1' and '0'. Please try again : ");
                    scanf("%d",&F[i][j]);
                }
                
                F[j][i]= F[i][j]; // populate duplicate array elements
                
                break;
            }
        }
    }
}

/* Δέχεται ως ορίσματα τον πίνακα F, το πλήθος size των χρηστών 	και τον κωδικό ενός χρήστη user και επιστρέφει το πλήθος των φίλων του χρήστη.  */
int findFriends (int **F, int size, int user) {
    
    int i, count=0; // temp variables
    
    for (i = 0; i < size; i++) // iterate through user's row
    {
        if (F[user][i]==1) count+=1; /* when element is 1, increment count*/
    }
    return count;
}

/* Δέχεται ως ορίσματα τον πίνακα F, το πλήθος size των χρηστών και τους κωδικούς user1, user2 δύο χρηστών. Υπολογίζει και επιστρέφει το πλήθος των κοινών φίλων των user1 και user2 */

int commonFriends (int **F, int size, int user1, int user2) {
  
    int i, count=0; // temp variables
    
    for (i = 0; i < size; i++)
    { /* Compare user's row elements by column, if both 1 increment count */
        if (F[(user1)][i]==1 && F[(user2)][i]==1) count +=1;
    }
    return count;
}

/* Δέχεται ως ορίσματα τον πίνακα F, το πλήθος size των χρηστών και έναν πίνακα S που αποθηκεύει το πλήθος των φίλων του κάθε χρήστη. Η συνάρτηση ταξινομεί τους χρήστες σε μη φθίνουσα διάταξη με βάση το πλήθος των φιλων τους. Εδώ χρησιμοποιείται η ταξινόμηση φυσσαλίδας.  */

void sortUsers (int **F, int size, int *S) {
  
    int i, j,k; /* temp loop variables  */
    int temp, swap; /* bubble sort variables. temp is to swap elements, swap is to count no. of swaps in each iteration. */
    
    /* Iterate through F array by row, add each element to S(S's elements already initialized to 0 in main).*/
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            S[i] += F[i][j];
        }
    }
    /* bubble sort of S array*/
    for (i = 0; i < size; i++)
    {
        swap=0; // initialize swap count
        /* after the i th iteration, the last i elements are sorted; no need to check again  */
        for (j = 0; j < size-(1+i); j++) 
        {
            if (S[j] > S[j+1])
            {
                temp = S[j+1];
                S[j+1] = S[j];
                S[j] = temp;
                swap++;
            }
        }
        if (swap==0) break; /* if no swaps occured in last iteration, array is sorted; exit loop. */
    }
}


