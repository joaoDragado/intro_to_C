/************************************************************
* ΠΛΗ10
* Εισαγωγή στη γλώσσα προγραμματισμού C.
* 
* 8o Αρχείο: 08_diaperasi_pinaka.c
*
* Αυτό είναι το όγδοο πρόγραμμα προς επίδειξη. 
* Πρόβλημα: Διαπέραση πίνακα και αναζήτηση κλειδιού
* Λύση: προσπέλαση πίνακα σειριακά με χρήση μετρητή. Καλείται συνάρτηση που επιστρέφει τη θέση του κλειδιού
* ή το -1 αν δεν το εντοπίσει
* Έννοιες που συναντάμε: συναρτήσεις που καλούνται από την main()
********************************************************/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[5]={12,2,7,14,5};
	int x=14,y,i;
	
	printf("We will search for a specific key number in the following array\n");
	for(i=0; i<5; i++) printf("%d\t",a[i]);
	printf("\nWe will search for the number %d\n",x);
	
	y=find_pos(x,a);
	if (y == -1)
        printf("Key number is not in the array\n");
	    else
        printf("Key number %d is in position number %d \n\n",x,y+1);
        
	system("pause");

}


int find_pos(int x, int a[])
{
	int i,pos=-1;
	for (i=0;i<5;i++)
		if (a[i]==x) pos=i;
	return(pos);
}
