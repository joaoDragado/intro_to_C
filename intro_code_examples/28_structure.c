/*****************************************************************************
 * ΠΛΗ10 
 * Εισαγωγή στη γλώσσα προγραμματισμού C.
 * 
 * 28o Αρχείο: 28_domi.c
 *
 * Αυτό είναι το εικοστό όγδοο πρόγραμμα προς επίδειξη.
 * Πρόβλημα: Να γράψετε τις αναγκαίες δηλώσεις για έναν πίνακα 50 θέσεων
 * του οποίου τα στοιχεία είναι εγγραφές (structs) με πεδία name, age,
 * salary. Στα πεδία αυτά θέλουμε να καταχωρούμε το όνομα, την ηλικία και
 * το μισθό αντίστοιχα, κάποιου ατόμου.
 * Λύση: Δημιουργούμε την struct και έπειτα με τις αντίστοιχες εντολές
 * πραγματοποιούνται οι εισαγωγές νέων εγγραφών και η εκτύπωση - εμφάνισή τους.
 * Έννοιες που συναντάμε: Δομή, εκτύπωση, προσθήκη εγγραφής
 ****************************************************************************/
 



#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef struct employee_record
{
    char name[20];
    int age;
    int salary;
} Employee_Record;


typedef Employee_Record Record_table[MAX_SIZE];

int AddEntry(Record_table personnel, int tot)
{
    char temp;
    if (tot > MAX_SIZE) // αν δεν υπάρχει αρκέτος χώρος στον πίνακα
    {
        return 0;
    }
    else
    {
        printf("Please enter name: ");
        scanf("%s",personnel[tot].name);
        printf("Please enter age: ");
        scanf("%d",&personnel[tot].age);
        printf("Please enter salary: ");
        
        do{
            scanf("%c",&temp);
        }while(temp != '\n');
        
        scanf("%d",&personnel[tot].salary);
        return 1;
    }
}

void PrintEntry(Employee_Record person)
{
    printf("Name:\t\t%s\n",person.name);
    printf("Age:\t\t%d\n",person.age);
    printf("Salary:\t\t%d\n",person.salary);
}

void PrintTable(Record_table personnel, int tot)
{
    int i;
    for(i=0;i<tot;i++)
    PrintEntry(personnel[i]);
}

int main()
{
    Record_table test;
    Employee_Record TEST;
    printf("Dwse ta stoixeia enos anthrwpou: \n");
    AddEntry(test, 0); 
    printf("\nEdwses ta parakatw stoixeia: \n");
    PrintEntry(test[0]);
    printf("Twra dwse ta stoixeia kai kapoiou allou!\n");
    AddEntry(test, 1);

    PrintTable(test , 2);
    system("pause");
    return 0;
}
///INPUT:
//JOHN
//18
//1337

///OUTPUT
//Edwses ta parakatw stoixeia:
//JOHN
//18
//1337
//Twra dwse ta stoixeia kai kapoiou allou!

///INPUT
//Jace
//21
//2

///OUTPUT
//JOHN
//18
//1337
//Jace
//21
//2
