#include <stdio.h>

void sort(int pos[], int speed[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(pos[j] < pos[j + 1])
            {
                int temp = pos[j];
                pos[j] = pos[j + 1];
                pos[j + 1] = temp;

                temp = speed[j];
                speed[j] = speed[j + 1];
                speed[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int target, n;

    scanf("%d", &target);
    scanf("%d", &n);

    int pos[100], speed[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &pos[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    sort(pos, speed, n);

    float time[100];

    for(int i = 0; i < n; i++)
        time[i] = (float)(target - pos[i]) / speed[i];

    int fleets = 0;
    float maxTime = 0;

    for(int i = 0; i < n; i++)
    {
        if(time[i] > maxTime)
        {
            fleets++;
            maxTime = time[i];
        }
    }

    printf("%d", fleets);

    return 0;
}