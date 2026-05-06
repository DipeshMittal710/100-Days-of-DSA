#include <stdio.h>

int isPossible(int arr[], int n, int students, int maxPages) {

    int count = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] > maxPages) {

            count++;
            pages = arr[i];

            if (count > students)
                return 0;
        }

        else {
            pages += arr[i];
        }
    }

    return 1;
}

int main() {

    int n, students;

    scanf("%d %d", &n, &students);

    int arr[100];

    int sum = 0;

    for (int i = 0; i < n; i++) {

        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int low = 0;
    int high = sum;
    int ans = sum;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (isPossible(arr, n, students, mid)) {

            ans = mid;
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}