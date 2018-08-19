﻿/************************************************************
* ΠΛΗ10
* Εισαγωγή στη γλώσσα προγραμματισμού C.
* 
* 10o Αρχείο: 10_loop.c
*
* Αυτό είναι το δέκατο πρόγραμμα προς επίδειξη. Το πρόγραμμα 
* παρουσιάζει βασικά θέματα της επαναληπτικής δομής do-while, 
* και της δομής if
*
 ************************************************************/
 
 #include <stdio.h>

main()
{
   int m,n;

   m=2; n=1;

   do //Έναρξη συνθήκης do-while, η οποία πραγματοποιεί το συγκεκριμένο Loop τουλάχιστον μία φορά και 
      //από εκεί και έπειτα το επαναλαμβάνει μέχρι το m να είναι διάφορο του n
   {
       m=m+5;

       //έλεγχος τιμής της μεταβλητής m
       if (m>=9) m=m-8;

       n=n+7;
       
       //έλεγχος τιμής της μεταβλητής n
       if (n>=6) n=n-9;

       printf("%d %d\n",m,n);

   } while (m != n);

}