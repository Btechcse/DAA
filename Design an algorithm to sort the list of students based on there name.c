/*
Assume you are a teacher. Design an algorithm to sort the list of students based
on their names
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(char str1[], char str2[])       //so that problem regarging small and capital letters can be solved
{
    char s1[100],s2[100];
    strcpy(s1,str1);
    strcpy(s2,str2);


    int i=0;
    while(s1[i]!='\0')                    //converting s1 to uppercase
    {
        if(s1[i]>='a'&&s1[i]<='z')
        {
            s1[i]-=32;
        }
        i++;
    }

    i=0;
    while(s2[i]!='\0')                     //converting s2 to uppercase
    {
        if(s2[i]>='a'&&s2[i]<='z')
        {
            s2[i]-=32;
        }
        i++;
    }

    if(strcmp(s1,s2)==1){return 1;}        //comparing uppercase strings
    else{return 0;}
}


int main()
{
    int n;
    printf("Enter number of students in list:");
    scanf("%d",&n);
    fflush(stdin);

    char list[n][100];

    int i;
 

    for(i=0;i<n;i++)
    {
        scanf("%[^\n]s",list[i]);
        fflush(stdin);

        if(i>1)
        {
            char key[100];
            strcpy(key,list[i]);
            int j=i-1;

            while(j>=0 && compare(list[j],key))
            {
                strcpy(list[j+1],list[j]);
                j--;
            }
        strcpy(list[j+1],key);

        }
     
    }

    printf("\nSorted List:\n");

    for(i=0;i<n;i++)
    {
        printf("%s \n",list[i]);
    }

}
