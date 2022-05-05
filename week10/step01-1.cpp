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

    for (int i=0; i<n; i++) {
        printf("%s %d\n", names[i], grades[i]);
    }
}
