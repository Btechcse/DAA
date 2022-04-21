/*
Design a recursive program to sort an array by
 repeatedly finding the smallest and largest 
 element of an array and replacing with the first and last element of the array. 
*/

#include <stdio.h>

void sort(int arr[],int low, int high)
{
    if(low<high )
    {
        int min_index=low,max_index=high;
        int i;
        for(i=low;i<=high;i++)
        {
            
            if(arr[i]<arr[min_index])
            {
                min_index=i;
            }
        }

        int temp=arr[low];
        arr[low]=arr[min_index];
        arr[min_index]=temp;
        
        for(i=low;i<=high;i++)
        {
            if(arr[i]>arr[max_index])
            {
                max_index=i;
            }

          
        }

       

        temp=arr[high];
        arr[high]=arr[max_index];
        arr[max_index]=temp;

        sort(arr,low+1,high-1);
    }
}

int main()
{
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);

    int i,arr[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    sort(arr,0,n-1);
    printf("\nSorted Array: ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
}