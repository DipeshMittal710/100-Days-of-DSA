#include <stdio.h>
#include <string.h>

int main() {

    char str[1000];

    scanf("%s", str);

    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {

        freq[(int)str[i]]++;

        if (freq[(int)str[i]] == 2) {
            printf("%c\n", str[i]);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}