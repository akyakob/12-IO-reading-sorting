/*---------------------------------------------------------------------------
  This prints out argv and env variables 
  student copy
---------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *env[]) {
   //your code here
   int i = 0;
   printf("Program name: %s\n", argv[0]); 
   if (argc == 1) {
	printf("No extra command line arguments other than program name\n");
   }
   if(argc >= 2) {
	printf("Command line arguments\n");
	while (i<argc) {
	  printf("argv[%d]: %s\n",i,argv[i]);
	  i++;
	}
   return 0;
   }
 return 0;
}
