#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {

    int size, q;

    scanf("%d", &size);
    scanf("%d", &q);

    int hashTable[size];

    for (int i = 0; i < size; i++) {
        hashTable[i] = EMPTY;
    }

    for (int k = 0; k < q; k++) {

        char operation[10];
        int key;

        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {

            int index = key % size;

            int i = 0;

            while (i < size) {

                int newIndex = (index + i * i) % size;

                if (hashTable[newIndex] == EMPTY) {
                    hashTable[newIndex] = key;
                    break;
                }

                i++;
            }
        }

        else if (strcmp(operation, "SEARCH") == 0) {

            int index = key % size;

            int found = 0;

            int i = 0;

            while (i < size) {

                int newIndex = (index + i * i) % size;

                if (hashTable[newIndex] == key) {
                    found = 1;
                    break;
                }

                if (hashTable[newIndex] == EMPTY)
                    break;

                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}