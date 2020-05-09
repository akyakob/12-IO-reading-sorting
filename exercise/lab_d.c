/* Applied Programming Examples: sorting.c
 * student copy
 *
 * Uses qsort() to sort an array of random polar data
 *
 * Use compiler directive -DN=size to change the size of the array
 *
 * Reference: A. Kelley and I Pohl "A book on C" 4th Ed.
 * Revised: 3/31/2015 (JCCK)
 */
 
#include <stdio.h>  
#include <math.h>
#include <float.h>
#include <stdlib.h> /* for qsort()    */

/* The polar data structure */
typedef struct {double mag; double ang;} polar;
int cmpdbl(const void *p1, const void *p2);
/* Add your polar compare function prototype here */
 
/* 
 Initialize an array of doubles of size N, with random numbers
 between -50 and 50, sort it and print it 
*/
int main(int argc, char *argv[]) {

   polar *array;
   int num;
   int i;
   
   // Check the command line entry
   if (argc < 2) {printf("not enough arguments\n");
                   return (3);} 
	num = atoi(argv[1]);
	if(num < 2) { 
	  printf("Entry needs to be greater than 2\n");
	  return 2;
	}
   // Get the memory
      array = malloc(num*sizeof(polar));

   // Initialize the array with random data, make one magnitude identical
   for(i = 0; i < num-1; ++i) {
      array[i].mag = (rand() % 1001) /10.0 - 50.0;
      array[i].ang = (rand() % 1001) /10.0 - 50.0;
   }
   // Identical 
   array[i].mag = array[i-1].mag;
   array[i].ang = (rand() % 1001) /10.0 - 50.0;


   // Sort the data
   qsort(array, num, sizeof(double), &cmpdbl);  
   qsort(array, num, sizeof(double), &cmpdbl);  
   
   
   // Print the sorted dat
   for(i = 0; i < num; ++i) {
      printf("%10.1f %10.1f\n", array[i].mag, array[i].ang);
   }
   printf("\n");   
return(0);
}  
 
/*---------------------------------------------------------------------------
  The compare function to use.  Cast p1 and p2 to polar in this case
---------------------------------------------------------------------------*/
int cmpdbl(const void *p1, const void *p2) {
 const polar *pol1;
 const polar *pol2;
 pol1 = p1;
 pol2 = p2;
  if(pol1->mag < pol2->mag)      {return -1;}
  else if(pol1->mag > pol2->mag) {return 1;}
  else if(pol1->ang < pol2->ang) {return -1;}
  else if(pol1->ang > pol2->ang) {return 1;}
  return 0; 
}
// add your function and code here
