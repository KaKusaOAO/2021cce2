#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    FILE *f = fopen("input.txt", "r");
    fscanf(f, "%d", &n);

    char names[n][32];
    int grades[n];

    memset(names, 0, n * 32);
    memset(grades, 0, sizeof(int) * n);

    for (int i=0; i<n; i++) {
        fscanf(f, "%s %d", names[i], &grades[i]);
    }

    int len = n;
    while (len > 1) {
        len--;

        for (int i=0; i<len; i++) {
            if (grades[i] < grades[i+1]) {
                // Grade swap
                int t = grades[i];
                grades[i] = grades[i+1];
                grades[i+1] = t;

                // Name swap
                char tn[32];
                memcpy(tn, names[i], 32);
                memcpy(names[i], names[i+1], 32);
                memcpy(names[i+1], tn, 32);
            }
        }
    }

    for (int i=0; i<n; i++) {
        printf("%s %d\n", names[i], grades[i]);
    }
}
