#include <stdio.h>
//implementation of selection sort using recursion

int prefix_max (int arr[], int i);
void swap(int *p, int *q);
void display(int arr[], int size);
void selectionSort (int arr[], int i);
void selectionSort (int arr[], int i)
{
    if(i == 0)
    return;

    int j = prefix_max(arr, i);
    swap(&arr[i], &arr[j]);
    selectionSort(arr, i - 1);
}

int prefix_max (int arr[], int i)
{
    if(i == 0)
    {
        return 0;
    }
    else
    {
        int j = prefix_max(arr, i - 1);
        return arr[i] < arr[j] ? j : i;
    }
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
}

int main(void)
{
    int arr[] = {5, 4, 6, 2, 1};
    selectionSort(arr, 4);
    display(arr, 5);
}