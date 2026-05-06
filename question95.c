#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    float arr[100];

    for(int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    float bucket[100][100];
    int count[100] = {0};

    for(int i = 0; i < n; i++)
    {
        int index = arr[i] * n;
        bucket[index][count[index]++] = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < count[i] - 1; j++)
        {
            for(int k = j + 1; k < count[i]; k++)
            {
                if(bucket[i][j] > bucket[i][k])
                {
                    float temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < count[i]; j++)
            printf("%.2f ", bucket[i][j]);
    }

    return 0;
}