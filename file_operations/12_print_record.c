/*
Πρόβλημα:  Γράψτε ένα πρόγραμμα για την εκτύπωση ενός συνόλου αρχείων, αρχίζοντας κάθε νέο αρχείο από νέα σελίδα,
με τίτλο και συνεχή αρίθμηση σελίδων χωριστά για κάθε αρχείο.

Λύση: Για να εκτελεστεί το πρόγραμμα, στην γραμμή εντολών του παραθύρου DOS,
πληκτρολογούμε τον όνομα του προγράμματος και τα ονόματα των αρχείων που θέλουμε να εκτυπωθούν.
Για παράδειγμα: 12_ektypwsi_arxeiwn arxeio1.txt arxeio2.txt

Έννοιες που συναντάμε: άνοιγμα, εκτύπωση και κλείσιμο αρχείων
*/

#include <stdio.h>

void filecopy(FILE *, FILE *);

void main(int argc, char *argv[])
{
     FILE* fp;
     int i=0;

     if (argc==-1)
        filecopy(stdin, stdout);
     else
         while (--argc >0)
         {
           i++;

           if ((fp=fopen(*++argv,"r"))==NULL)  // Αδυναμία ανοίγματος αρχείου (π.χ. όταν το αρχείο δεν υπάρχει).
             printf("The file %s can not be opened",*argv);
           else
           {
              printf("\f The file %s is Printed\n",*argv);
              filecopy(fp,stdout);
              fclose(fp);
              printf("\n  %d",i);
           }
          }
}

// Αντιγραφή περιεχομένων ενός αρχείου σε ένα άλλο.
void filecopy(FILE *ifp, FILE* ofp)
{
 int c;

 while ((c=getc(ifp))!=EOF)  // Ενόσω δε συναντούμε το χαρακτήρα End Of File ...
       putc(c,ofp);
}
