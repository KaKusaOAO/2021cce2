#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Student {
public:
    char name[32];
    int grade;
};

int main() {
    int n;
    FILE *f = fopen("input.txt", "r");
    fscanf(f, "%d", &n);

    Student scores[n];
    memset(scores, 0, sizeof(Student) * n);

    for (int i=0; i<n; i++) {
        fscanf(f, "%s %d", scores[i].name, &scores[i].grade);
    }

    int len = n;
    while (len > 1) {
        len--;

        for (int i=0; i<len; i++) {
            if (scores[i].grade < scores[i+1].grade) {
                // Grade swap
                Student t = scores[i];
                scores[i] = scores[i+1];
                scores[i+1] = t;
            }
        }
    }

    for (int i=0; i<n; i++) {
        printf("%s %d\n", scores[i].name, scores[i].grade);
    }
}
