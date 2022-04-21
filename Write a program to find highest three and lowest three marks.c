/*
Assume you are a teacher. Write a program to find highest three and lowest three marks obtained in DAA.
*/


#include <stdio.h>

void countingSort(int array[], int size) {
  int output[size];

  // Find the largest element of the array
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }


  int count[max];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}


int main()
{
    
        int n;
        printf("Size of marks list:");
        scanf("%d",&n);
        int marks[n];
        int i;


        printf("Enter list of marks:");

        for(i=0;i<n;i++)
        {
            scanf("%d",&marks[i]);
        }


        int k;
        

        countingSort(marks,n);

        printf("\n\nHighest three marks:\n");
        i=n-1;
        for(k=0;k<3;)
        {
            
            if(marks[i]!=marks[i-1])
            {
                printf("%d\n",marks[i]);
                k++;
            }
            i--;
        }

        printf("\n\nLowest three marks:\n");
        i=0;
        for(k=0;k<3;)
        {
            
            if(marks[i]!=marks[i+1])
            {
                printf("%d\n",marks[i]);
                k++;
            }
            i++;
        }
        

        

     
}