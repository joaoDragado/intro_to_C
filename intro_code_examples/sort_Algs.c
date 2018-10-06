#include <stdio.h>
#include <stdlib.h>
/*bubble sort - iterative*/

void bubbleSort(int *numbers, int array_size)
{
  int i, j, temp;
 
  for (i = (array_size - 1); i > 0; i--)
  {
    for (j = 1; j <= i; j++)
    {
      if (numbers[j-1] > numbers[j])
      {
        temp = numbers[j-1];
        numbers[j-1] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
}

/*selection sort - iterative*/

void selectionSort(int *arr, int array_size){
    
    int i, j, temp ;
    
    for ( i = 0 ; i < (array_size - 1) ; i++ )
    {
        for ( j = i + 1 ; j < array_size ; j++ )
        {
            if ( arr[i] > arr[j] )
            {
                temp = arr[i] ;
                arr[i] = arr[j] ;
                arr[j] = temp ;
            }
        }
    }
}

/* insertion sort - iterative*/

void insertSort(int *a, int n) {
    
    int j,i,key;
    
    for (i = 1; i < n; ++i) {
        key = a[i];
        j = i - 1;
            while ((j >= 0) && (key < a[j])) {
            a[j + 1] = a[j];
            --j;
    }
    a[i + 1] = key;
    }
}

/* quick sort - iterative*/

void quicksort(int *data, int N){
    
    int i, j, pivot, temp;
    
    if( N <= 1 )  return;
    
    // Partition elements
    pivot = data[0];
    i = 0;
    j = N;
    
    while(1) {
        do {i++;}
            while(data[i] <= pivot && i < j); 
        do {j--;}    
            while(data[j] > pivot);
        if( i >= j )
            break;
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    temp = data[i-1];
    data[i-1] = data[0];
    data[0] = temp;
    quicksort(data, i-1);
    quicksort(data+i, N-i);
}

/*heap sort - in-place, ierative*/

void heapSort(int numbers[], int array_size) {
  int i, temp;
 
  for (i = (array_size / 2); i >= 0; i--) {
    siftDown(numbers, i, array_size - 1);
  }
 
  for (i = array_size-1; i >= 1; i--) {
    // Swap
    temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
 
    siftDown(numbers, 0, i-1);
  }
}
 
void siftDown(int numbers[], int root, int bottom) {
  int maxChild = root * 2 + 1;
 
  // Find the biggest child
  if(maxChild < bottom) {
    int otherChild = maxChild + 1;
    // Reversed for stability
    maxChild = (numbers[otherChild] > numbers[maxChild])?otherChild:maxChild;
  } else {
    // Don't overflow
    if(maxChild > bottom) return;
  }
 
  // If we have the correct ordering, we are done.
  if(numbers[root] >= numbers[maxChild]) return;
 
  // Swap
  int temp = numbers[root];
  numbers[root] = numbers[maxChild];
  numbers[maxChild] = temp;
 
  // Tail queue recursion. Will be compiled as a loop with correct compiler switches.
  siftDown(numbers, maxChild, bottom);
}

/*merge sort - iterative
The merge sort divides the array into two sub-arrays, sorts them and then calls merge to merge the two arrays back together. */

void merge( int *a, int *b, int *c, int m, int n ){
    
    int i = 0, j = 0, k = 0;
    while (i < m && j < n){
        if( a[i] < b[j] ) 
            c[k++] = a[i++];
        else 
            c[k++] = b[j++];
    }
    
    while ( i < m )
        c[k++] = a[i++];
    
    while ( j < n )
        c[k++] = b[j++];
    
}
 
void merge_sort( int *key, int n ){
    
    int j, k, m, *w;
    
    for( m = 1; m < n; m *= 2 );
    if (m != n)
        printf ("ERROR: Size of the array is not power of 2.");
    else {
        w = calloc( n, sizeof(int) );
        
        for ( k = 1; k < n; k *= 2 ){
            
            for ( j = 0; j < (n - k); j += 2 * k ){
            
                merge(key + j, key + j + k, w + j, k, k);
            }
        
          for ( j = 0; j < n; j++) 
            key[j] = w[j];
        }
        
        free(w);
    }
}

