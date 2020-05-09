/*---------------------------------------------------------------------------
  This program demonstrates the limitations of scanf() and the use of fseek()
  student copy
---------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 256

int main(int argc, char *argv[]) {
   // File name to read and the handle
   FILE *DataFile = NULL;
   char *fileName = "data.txt";
   
   // The data to parse
   int num, v1, v2, v3;
   char *buffer;
   char display;
   
   if(argc != 2) {exit(99);}

   num = atoi(argv[1]);

   // Get memory
   buffer = (char*)malloc(sizeof(char) * BUFF_SIZE); 
   if (NULL == buffer) {
      printf("Malloc error\n");
      exit(99);
   }
   
   // Open the data
   DataFile = fopen(fileName, "r");
   if (NULL == DataFile) {
      printf("Error could not open '%s'\n", fileName);
   }
      
   // Read all the EXACT data in the file using fgets(), in a while loop
   // and print the results out, removing any trailing LF \n character, if any.
   while (1){
	fgets(buffer, BUFF_SIZE, DataFile);
      // remove the lf at the end
	if(strlen(buffer)) {
	 buffer[strlen(buffer)-1] = 0;
	}
      printf("Read: '%s'\n", buffer);
	if(feof(DataFile)) { break; }
   } 
   
   // Use fseek() to start back at the beginning of the file
      fseek(DataFile, 0, SEEK_SET);
   
   // Read all the data in the file and print the results out
   while (fscanf(DataFile, "%d %d %d ", &v1, &v2, &v3) ==1 ){
      printf("%d parameters %d %d %d\n", num, v1, v2, v3);
   } 
   
   // Return memory, close files 
   free(buffer);
   fclose(DataFile);
   return(0);
}  
