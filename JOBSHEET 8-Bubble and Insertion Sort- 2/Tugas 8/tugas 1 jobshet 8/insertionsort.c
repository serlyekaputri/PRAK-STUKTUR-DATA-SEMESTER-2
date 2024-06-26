// Createad_by_Serly Eka Putri_23343083

#include <stdio.h>

void insertionSort(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
	{
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() 
{
    int arr[] = {17, 31, 25, 12, 22, 11, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printf("Sorted array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}