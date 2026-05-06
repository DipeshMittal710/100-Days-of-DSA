#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100];

    int max = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        if(arr[i] > max)
            max = arr[i];
    }

    int count[1000] = {0};

    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;

    for(int i = 0; i <= max; i++)
    {
        while(count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}