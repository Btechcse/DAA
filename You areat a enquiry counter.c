/*
You areat a enquiry counter. 
Design a program to sort the list of people that arrives at the counter
board, on their age. After each entry the list should remain sorted 
*/

//we will use insertion sort
//we will see for 10 person

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int list[10];
    int i,count=0;
    for(i=0;i<10;i++)
    {
        printf("Enter age of person:");
        scanf("%d",&list[i]); //new person coming
        count++;

        if(i>0)
        {
            int key=list[i];
            int j=i-1;
            while(list[j]>key&&j>=0)
            {
                list[j+1]=list[j];
                j--;
            }

            list[j+1]=key;
        }

        int k;
        printf("\nList after new entry: ");
        for(k=0;k<count;k++)          //displaying list after new entry
        {
            printf("%d ",list[k]);
        }
        printf("\n");
    }

}
