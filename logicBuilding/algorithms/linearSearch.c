#include <stdio.h>

int linearSearch(int array[], int n, int num);

int main()
{

    int arr[] = {2, 3, 1, 5, 65, 8, 4, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    int num = linearSearch(arr, size, 4);
    printf("value is : %d\n", num);
    return 0;
}

void printArray(int array[], int size)
{
    printf("Elements of the array are : ");
    for(int i = 0; i < size; i++)
    {
        printf("%d, ",array[i]);
    }
    printf("\n");
}

int linearSearch(int array[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if(array[i] == num)
        {
            return i;
        }
    }

    return -1;
}