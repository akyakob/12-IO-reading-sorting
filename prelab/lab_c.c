/* Applied Programming Examples: sorting.c
 * student copy
 *
 * Uses qsort() to sort an array of random doubles
 *
 */
 
#include <stdio.h>  
#include <stdlib.h> /* for qsort()    */

/* Function prototypes */
int cmpdbl(const void *p1,const void *p2); /* for qsort() */
 
/* 
 Initialize an array of doubles of size N, with random numbers
 between -50 and 50, sort it and print it 
*/
int main(int argc, char *argv[]) {
   double *array;
   int num;
   
   // Check the command line entry
   if (argc < 2) {printf("not enough arguments\n");
                   return (3);} 
	num = atoi(argv[1]);
	if(num < 2) { 
	  printf("Entry needs to be greater than 2");
	  return 2;
	}
   // Get the memory
      array = malloc(num*sizeof(double));
   
   // Initialize the array with random data
   for(int i = 0; i < num; ++i) {
     array[i] = (rand() % 1001) /10.0 - 50.0;
   }
   
   // Sort the data
   qsort(array, num, sizeof(double), &cmpdbl);  
 
   // Print the sorted data
   for(int i = 0; i < num; ++i) {
      printf("% 10.1f\n", array[i]);
   }
   printf("\n");   
return(0);
}  
 
/*---------------------------------------------------------------------------
  The compare function to use.  Cast p1 and p2 to doubles in this case
---------------------------------------------------------------------------*/
int cmpdbl(const void *p1, const void *p2) {
  if(*(double*)p1 < *(double*)p2)      {return -1;}
  else if(*(double*)p1 > *(double*)p2) {return 1;}
  return 0; 
}


