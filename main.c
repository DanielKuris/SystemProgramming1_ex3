#include <stdio.h>
#include "StrList.h"
#define SIZE 200

// Helper function to get story input
// Reading input of unknown length of strings
// Running until recieved "words" amount of words.
char *inputString() {
    size_t size = SIZE; // Start with some initial size
    char *str = (char *)malloc(size * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t len = 0; // Current amount of chars (used memory)
    char ch; // Current input char (stored as an integer)
    while ((scanf(" %c", &ch)) != ' ' && ch != '\n') {
        str[len++] = (char) ch; // Convert integer to character and store in the string
        if (len == size) { // Increasing memory allocation if reached the previous one
            size *= 2;
            str = (char *)realloc(str, size * sizeof(char));
            if (str == NULL) {
                printf("Memory reallocation failed\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    str[len] = '\0'; // Null-terminate the string
    return str;
}


int main(){
   StrList* StrList= StrList_alloc();
   int input;
   char *str[SIZE];
   int index;

   
   do {

    scanf(" %d", &input); //Get operation

    switch (input)
    {
    case 1: //Setting list with "words" amount of words
        int words;
        scanf(" %d", &words); //Get amount of words
        
        for(int word = 0; word<words; word++){
            scanf(" %s", str); //Get input 
            StrList_insertLast(StrList, str);
        }

        break;
    

    case 2: //Insert str at given index in list
        scanf(" %d",&index);
        scanf(" %s", str); //Get input 
        StrList_insertAt(StrList, str, index);
        break;


    case 3: //Print the list's content
        StrList_print(StrList);

        break;


     case 4: //Print the amount of nodes in the list
        printf("%zu",StrList_size(StrList));
        printf("\n");


        break;


    case 5: //Print data of a node at location index
        scanf(" %d",&index);
        StrList_printAt(StrList,index);

        break;


    case 6: //Print the amount of chars in the list
        printf(" %d",StrList_printLen(StrList));
        printf("\n");


        break;


    case 7: //Print how many times a string appears in the list
        scanf(" %s", str); //Get input 
        printf(" %d", StrList_count(StrList, str)); 
        printf("\n");

        free(str);

        break;

    case 8: //Delete a string completely from the list
        scanf(" %s", str); //Get input 
        StrList_remove(StrList, str);
        free(str);

        break;


    case 9: //Delete the node at location index
        scanf(" %d",&index);
        StrList_removeAt(StrList, index);

        break;


    case 10: //Reverse the list
        StrList_reverse(StrList);

        break; 


    case 11: //Delete the list
        StrList_free(StrList);
        StrList= StrList_alloc();

        break;


    case 12: //Sort the list in a lexicographic order
        StrList_sort(StrList);
        break; 


    case 13: //Returning 1 if sorted and 0 if not (lexicographic order)
       if(StrList_isSorted(StrList)){
            printf("true");
            printf("\n");
        }else{
            printf("false");
            printf("\n");
        }
            
        break; 


    case 0: //Exiting the program
        StrList_free(StrList);
        break;

    }
   }
   while(input!=0); //Do operation while the chosen operation is not 0
   
 return 0;
}

