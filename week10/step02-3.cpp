#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <vector>

class Student {
public:
    char name[32];
    int grade;
};

bool comparer(Student a, Student b) {
    return a.grade > b.grade;
}

int main() {
    int n;
    FILE *f = fopen("input.txt", "r");
    fscanf(f, "%d", &n);

    std::vector<Student> scores;

    for (int i=0; i<n; i++) {
        Student s;
        fscanf(f, "%s %d", s.name, &s.grade);
        scores.push_back(s);
    }

    std::sort(scores.begin(), scores.end(), comparer);

    for (int i=0; i<n; i++) {
        printf("%s %d\n", scores[i].name, scores[i].grade);
    }
}
