#include <stdio.h>

void mergeSort(int array[], int start, int end);
void printSubArray(int arr[], int start, int end);
void merge(int array[], int start, int end, int mid);

int main()
{
    int size = 9;
    int arr [] = {33, 3, 72, 9, 5, 12, 8, 9, 1};
    mergeSort(arr, 0, size - 1);
    printSubArray(arr, 0, size - 1);

    return 0;
}

void mergeSort(int array[], int start, int end)
{
    if(start == end) return;
    int mid = start + ((end - start) / 2);
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);
    printf("start index : %d -",start);
    printf(" end index : %d\n",end);
    merge(array, start, end, mid);

    // printSubArray(array, start, end);

}

void merge(int array[], int start, int end, int mid)
{
    int leftPtr = start;
    int rightPtr = mid + 1;
    int temp[end - start + 1];
    int tempPtr = 0;

    while(leftPtr <= mid && rightPtr <= end)
    {
        if(array[leftPtr] <= array[rightPtr])
        {
            temp[tempPtr] = array[leftPtr];
            leftPtr++;
            tempPtr++;
        } 
        else 
        {
            temp[tempPtr] = array[rightPtr];
            rightPtr++;
            tempPtr++;
        }

        if(leftPtr > mid)
        {
            for(int i = rightPtr; i <= end; i++)
            {
                temp[tempPtr] = array[i];
                tempPtr++;
            }

            break;
        } 
        else if(rightPtr > end)
        {
            for(int i = leftPtr; i <= mid; i++)
            {
                temp[tempPtr] = array[i];
                tempPtr++;
            }

            break;
        }
    }

    // printSubArray(temp, 0, end - start);
    for(int i = 0; i <= end - start; i++)
    {
        array[start + i] = temp[i];
    }
}

void printSubArray(int arr[], int start, int end)
{
    printf("Array contents are: ");
    for(int i = start; i <= end; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
}

