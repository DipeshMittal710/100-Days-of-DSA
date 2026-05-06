#include <stdio.h>
#include <string.h>

int main() {

    char str[1000];

    scanf("%s", str);

    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }

    for (int i = 0; str[i] != '\0'; i++) {

        if (freq[(int)str[i]] == 1) {
            printf("%c\n", str[i]);
            return 0;
        }
    }

    printf("$\n");

    return 0;
}