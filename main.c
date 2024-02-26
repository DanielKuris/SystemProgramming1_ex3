#include <stdio.h>
#include "StrList.h"
#define SIZE 10

// Helper function to get story input
// Reading input of unknown length of strings
// Running until recieved "words" amount of words.
char *inputString(size_t words) {

    size_t size = SIZE; // Start with some initial size
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
    case 1: //Setting list with "words" amount of words
        scanf("%d", &words); //Get amount of words
            
        char *str = inputString(words); //Get input using helper function
        StrList_insertLast(StrList, str);
        free(str);

        break;
    

    case 2: //Insert str at given index in list
        scanf(" %d",&index);
        char *str = inputString(1); //Get input using helper function
        StrList_insertAt(StrList, str, index);
        free(str);
        break;


    case 3: //Print the list's content
        StrList_print(StrList);

        break;


     case 4: //Print the amount of nodes in the list
        printf(" %d",StrList_size(StrList));

        break;


    case 5: //Print data of a node at location index
        scanf(" %d",&index);
        StrList_printAt(StrList,index);

        break;


    case 6: //Print the amount of chars in the list
        printf(" %d",StrList_printLen(StrList));

        break;


    case 7: //Print how many times a string appears in the list
        char *str = inputString(1); // Get input using helper function
        printf(" %d", StrList_count(StrList, str)); 

        break;

    case 8: //Delete a string completely from the list
        char *str = inputString(1); // Get input using helper function
        StrList_remove(StrList, str);

        break;


    case 9: //Delete the node at location index
        scanf(" %d",&index);
        StrList_removeAt(StrList, index);

        break;


    case 10: //Reverse the list
        StrList_reverse(StrList);

        break; 


    case 11:
    //should remove all the list- need to be fixed
       StrList_remove(StrList, NULL);
        break;


    case 12: //Sort the list in a lexicographic order
       StrList_sort(StrList);
        break; 


    case 13: //Returning 1 if sorted and 0 if not (lexicographic order)
       StrList_isSorted(StrList);
        break;                                
    }
   }
   while(input!=0);
   
 return 0;
}

