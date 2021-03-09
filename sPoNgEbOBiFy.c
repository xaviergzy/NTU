
#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{

    int i,j=0;

    char sent[100];
    printf("Enter sentence to spongebobify.\n");
    fgets(sent, 100, stdin);

    char neww[100];

    for (i = 0; i < strlen(sent); i++) {
        if (sent[i] == ' ') {
            printf(" ");

            if (i%2 == 0) {
                    printf("%c", toupper(sent[i+1]));
                    } else {
                        printf("%c", tolower(sent[i+1]));
                        };

            i++;
            continue;
        }

        if (i % 2 == 0) {
            neww[j] = toupper(sent[i]);
            printf("%c", neww[j]);
            j++;
        } else {
            neww[j] = tolower(sent[i]);
        printf("%c", neww[j]);
            j++;
        }

    }


   return 0;
}
