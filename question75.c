#include <stdio.h>

struct Hash {
    int sum;
    int index;
};

int main() {

    int n;

    scanf("%d", &n);

    int arr[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Hash hash[2000];

    int size = 0;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int found = 0;

        for (int j = 0; j < size; j++) {

            if (hash[j].sum == sum) {

                int len = i - hash[j].index;

                if (len > maxLen)
                    maxLen = len;

                found = 1;
                break;
            }
        }

        if (!found) {

            hash[size].sum = sum;
            hash[size].index = i;
            size++;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}