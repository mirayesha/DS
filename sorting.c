#include <stdio.h>
#include <stdbool.h>

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

void bubbleSort(int arr[], int size)
{
    bool swapped;
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1 ; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
        return;
    }
}
void insertionSort(int arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void merge (int arr[],int l ,int  c ,int r)
{
    int size1 = c - l + 1;
    int size2 = r - c;

    int L[size1];
    int R[size2];

    for(int i = 0; i < size1; i++)
    {
        L[i] = arr[i+l];
    }

    for(int j = 0; j < size2; j++)
    {
        R[j] = arr[c + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while(i < size1 && j < size2)
    {
        if(L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while(i < size1)
    {
        arr[k++] = L[i++];
    }

    while(j < size2)
    {
        arr[k++] = R[j++];
    }
}
void mergeSort(int arr[],int l, int r)
{
    if(l < r)
    {
    int c = l + (r - l) / 2;
    mergeSort(arr, l , c);
    mergeSort(arr, c+1, r);

    merge(arr, l, c, r);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;
    int j = i - 1;

    while(i < high)
    {
        if(arr[i] < pivot)
        {
            swap(&arr[i], &arr[++j]);
        }
        i++;
        
    }
    swap(&arr[high], &arr[j + 1]);
    return j + 1;
}
void quickSort(int arr[],int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main(void)
{
    int arr[] = {5, 2, 6, 4, 7};
    quickSort(arr, 0, 4);
    display(arr, 5);
    printf("\n");
    
}