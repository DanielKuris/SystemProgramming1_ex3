#include <stdio.h>
#include "StrList.h"
#include "StrList.c"
#define SIZE 10

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

                for (int i = 0; i < index; i++) {
                    printf("Enter string: ");
                    scanf(" %s", str);
                    StrList_insertLast(StrList, str);
                }
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

