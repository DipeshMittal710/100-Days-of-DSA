#include <stdio.h>

long long merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[100], R[100];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    long long inv = 0;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
            inv += (n1 - i);
        }
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];

    return inv;
}

long long mergeSort(int arr[], int left, int right)
{
    long long inv = 0;

    if(left < right)
    {
        int mid = (left + right) / 2;

        inv += mergeSort(arr, left, mid);
        inv += mergeSort(arr, mid + 1, right);

        inv += merge(arr, left, mid, right);
    }

    return inv;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%lld", mergeSort(arr, 0, n - 1));

    return 0;
}