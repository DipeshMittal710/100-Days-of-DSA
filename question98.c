#include <stdio.h>

void sort(int start[], int end[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(start[j] > start[j + 1])
            {
                int temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;

                temp = end[j];
                end[j] = end[j + 1];
                end[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int start[100], end[100];

    for(int i = 0; i < n; i++)
        scanf("%d %d", &start[i], &end[i]);

    sort(start, end, n);

    int s = start[0];
    int e = end[0];

    for(int i = 1; i < n; i++)
    {
        if(start[i] <= e)
        {
            if(end[i] > e)
                e = end[i];
        }
        else
        {
            printf("%d %d\n", s, e);

            s = start[i];
            e = end[i];
        }
    }

    printf("%d %d\n", s, e);

    return 0;
}