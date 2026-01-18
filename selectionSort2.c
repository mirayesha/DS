#include <stdio.h>
//implementation of selection sort using loops

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void selectionSort(int arr[], int size)
{
    for(int j = size-1; j >= 0; j--)
    {
        int max_no = arr[j];
        for(int i = 0; i < j ; i++)
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[j], &arr[i]);
            }
        }
        if(max_no == arr[j])
        return;
    }
}

int main(void)
{
    int arr[] = {5, 4, 6, 2, 1};
    selectionSort(arr, 5);
    display(arr, 5);
}