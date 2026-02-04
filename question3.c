#include <stdio.h>

#define SIZE 5
void main()
{
    int arr[SIZE], item, flag, index;
    int compCount = 0;
    printf("Enter %d elements\n", SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the item to be searched: \n");
    scanf("%d", &item);
    flag = 0;

    for(int i = 0; i < SIZE; i++)
    {
        compCount++;
        if(arr[i] == item)
        {
            flag = 1;
            index = i;
            break;
        }
    }

    if(flag == 1)
    {
        printf("Item found at index: %d with %d comparisons\n", index, compCount);
    }
    else
    {
        printf("Item not found in the array\n");
    }
}