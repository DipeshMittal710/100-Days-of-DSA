#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[i])
                count++;
        }

        printf("%d ", count);
    }

    return 0;
}