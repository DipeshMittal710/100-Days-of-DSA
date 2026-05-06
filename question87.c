#include <stdio.h>

int main() {

    int n;

    scanf("%d", &n);

    int arr[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;

    scanf("%d", &x);

    int low = 0;
    int high = n - 1;
    int found = -1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid] == x) {

            found = mid;
            break;
        }

        else if (arr[mid] < x) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    printf("%d\n", found);

    return 0;
}