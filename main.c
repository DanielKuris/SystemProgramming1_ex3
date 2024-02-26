#include <stdio.h>
#include "StrList.h"
#include "StrList.c"
#define SIZE 10

// Helper function to get story input
// Reading input of unknown length of strings
// Running until recieved "words" amount of words.
char *inputString(size_t words) {

    size_t size = 10; // Start with some initial size
    char *str = (char *)malloc(size * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t len = 0;
    size_t wordCount = 0;
    int ch;
    while (wordCount < words) {
        ch = getchar();
        if (ch == ' ' || ch == '\n') {
            if (len > 0) {
                str[len++] = '\0'; // Null-terminate the word
                wordCount++;
                len = 0; // Reset the length for the next word
            }
        } else {
            str[len++] = ch;
            if (len == size) { //Increasing memory allocation if reached the previous one
                size *= 2;
                str = (char *)realloc(str, size * sizeof(char));
                if (str == NULL) {
                    printf("Memory reallocation failed\n");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    str[len] = '\0'; // Null-terminate the last word
    return str;
}

int main(){
StrList* StrList= StrList_alloc();
   int input;
   char str[SIZE];
   int index;

   
   do {
    scanf(" %d", &input);
    if (input==0) return 0;

    switch (input)
    {
    case 1:
             printf("Enter size of the array: ");
                scanf("%d", &index);
            
             char *str = inputString(index); //Get input using helper function
             StrList_insertLast(StrList, str);
             free(str)
             
        scanf(" %d",&input);
        break;
    

    case 2:
        scanf(" %d",&index);
        StrList_insertAt(StrList, str[index], index);
        break;


    case 3:
       StrList_print(StrList);
        break;


     case 4:
       printf(" %d",StrList_printLen(StrList));
        break;


    case 5:
       scanf(" %d",&index);
       StrList_printAt(StrList,index);
        break;


    case 6:
     //  scanf(" %s", data);
      // StrList_count(StrList, data);
        break;


  // case 7:
   //print how many times the str
   
    case 8:
     //  scanf(" %s", &data);
      // StrList_remove(StrList, data);
        break;


    case 9:
       scanf(" %d",&index);
       StrList_removeAt(StrList, index);
        break;


    case 10:
      StrList_reverse(StrList);
        break; 


    case 11:
    //should remove all the list- need to be fixed
       StrList_remove(StrList, NULL);
        break;


    case 12:
       StrList_sort(StrList);
        break; 


    case 13:
       StrList_isSorted(StrList);
        break;                                
    }
   }
   while(input!=0);
   
 return 0;
}

