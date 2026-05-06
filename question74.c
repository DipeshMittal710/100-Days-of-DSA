#include <stdio.h>
#include <string.h>

struct Candidate {
    char name[100];
    int votes;
};

int main() {

    int n;

    scanf("%d", &n);

    struct Candidate candidates[100];

    int count = 0;

    for (int i = 0; i < n; i++) {

        char temp[100];

        scanf("%s", temp);

        int found = 0;

        for (int j = 0; j < count; j++) {

            if (strcmp(candidates[j].name, temp) == 0) {

                candidates[j].votes++;
                found = 1;
                break;
            }
        }

        if (!found) {

            strcpy(candidates[count].name, temp);
            candidates[count].votes = 1;
            count++;
        }
    }

    char winner[100];
    int maxVotes = 0;

    for (int i = 0; i < count; i++) {

        if (candidates[i].votes > maxVotes) {

            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
        }

        else if (candidates[i].votes == maxVotes) {

            if (strcmp(candidates[i].name, winner) < 0) {
                strcpy(winner, candidates[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}