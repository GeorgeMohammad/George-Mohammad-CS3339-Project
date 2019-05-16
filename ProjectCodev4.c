

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Gets the index of a char in a cstring.
int GetIndex(char searchStr[100], char char1){
  for (int i = 0; i < 100; ++i){
        if (searchStr[i] == char1){
            return i;
        }
    }
    return -1;
}

int main() {
  //size of input file, number of lines.
   int size = 5911;
   FILE *fileI;
   //opening input file
   fileI = fopen("data.txt", "r");
   //dynamically allocating memory for input file (2d array).
   
   char **testFileHolder = malloc(size * sizeof(char*));
    for (int i = 0; i < size; ++i){
      testFileHolder[i] = (char*) malloc(size * sizeof(char*));
    }

    int index = 0;
    char character[1];
    int counter = 0;
    char temp[size];
    //reading the file into an array.
    while (index < size){
        while (character[0] != '\n'){

            character[0] = fgetc(fileI);
            testFileHolder[index][counter] = character[0];
            ++counter;
        }
        counter = 0;
        ++index;
	character[0] = '1';
        
        
    }
    fclose(fileI);
    
    char firstLetter = 'a';
    char secondLetter = 'a';
    //dynamically allocating memory for the output 2d array.
    char **result = malloc(size * sizeof(char*));//[10000 * sizeof(char)];
    for (int i = 0; i < size; ++i){
        result[i] = malloc(size * sizeof(char));
    }
    int resultCount = 0;
    int a;
    int charIndex1;
    int charIndex2;

    //the following two variables ensure multiple items will be grabbed per
    //letter using modulus.
    int firstLetterCount = 0;
    int secondLetterCount = 0;
    //Loops through the file and grabs entries that meet the criteria
    //in the subsequent if statement.
    for (int j = 0; j < 100; ++j){
       firstLetter = 'a';
        for (int k = 0; k < size; ++k){
	  charIndex1 = GetIndex(testFileHolder[k], firstLetter);
	  charIndex2 = GetIndex(testFileHolder[k], secondLetter);
	  if ((charIndex1 >						\
	       charIndex2) && ((charIndex1 >= 0) && (charIndex2 >= 0))){
		strcpy(result[resultCount], testFileHolder[k]);		
                ++resultCount;
		++firstLetterCount;
		if ((firstLetterCount % 10) == 0){
		  ++firstLetter;
		}
            }
            
            
        }
	++secondLetterCount;
	if ((secondLetterCount % 10) == 0){
	  ++secondLetter;
	}
    }

    FILE *fileO;
    fileO = fopen("output.txt", "a+");
    //writing to the file, output.txt.
    for (int i = 0; i < resultCount; ++i){
      if (strcmp(result[i], "\0")){
	fputs(result[i], fileO);
      }
    }
    fputs("\n\n\n", fileO);
    fclose(fileO);
    //assigning each element in the dynamically allocated arrays to NULL.
    for (int i = 0; i < 10000; ++i){
       testFileHolder[i] = NULL;
       result[i] = NULL;
    }
    //freeing and assigning the dynamically allocated arrays to NULL.
    free(testFileHolder);
    testFileHolder = NULL;
    free(result);
    result = NULL;
     
    
    return 0;
}

