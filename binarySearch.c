#include <stdio.h>
int binarySearch(int arr[], int high, int low, int num);
int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int high = 9;
    int low = 0;
    int index = binarySearch(arr, high, low, 71);
    if(index == -1)
    {
        printf("Not found");
    }
    else
    {
        printf("found at index %d", index + 1);
    }
    
}
int binarySearch(int arr[], int high, int low, int num)
{
    int mid = low + (high - low) / 2;
    if(low > high)
    {
        return -1;
    }
    else if(num == arr[mid])
    {
        return mid;
    }
    else if(num > arr[mid])
    {
        low = mid + 1;
        return binarySearch(arr, high, low, num);
    }
    else
    {
        high = mid - 1;
        return binarySearch(arr, high, low, num);
    }
}