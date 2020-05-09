/*---------------------------------------------------------------------------
   Applied Programming Examples: fscanf()
   student copy.  Define  -DMAX_STR=<num>  to control the buffer size 
   code defaults to 8.
---------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// For safety
#ifndef MAX_STR
   #define MAX_STR  8
#endif

int main(int argc, char *argv[]) {
   // Get space for our buffer
   char *string = malloc((MAX_STR+1)*sizeof(char)); 
   if (NULL == string) {
      printf("Malloc error\n");
      exit(99);
   }
   
   // Our read format string 
   char parseCMD [MAX_STR] = {"%s"};          // Student file

   
   // Tell the TA what the format string is
   printf("The parsing string '%s'\n\n", parseCMD);
   
   // Process all the data and print it out
   // Buffer overflows will be identified by vagrind
   while (1) {
      printf("Enter string or 'q' to exit: ");
      scanf(parseCMD, string);
 
   sprintf(parseCMD,"\nString '%s' length=%ld\n", string, strlen(string));
   printf("%s\n",parseCMD);
  // printf("\nString '%s' length=%ld\n", string, strlen(string));
   if (strcmp(string, "q") == 0) {
      free(string);
      exit(0);
      }
   }
return(0);
}  
