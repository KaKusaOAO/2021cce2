#include <cstdio>

int a[10] = {7,8,9, 1,2,3, 6,5,4, 0};

int main() {
    // Bubble Sort
    for (int i=0; i<10-1; i++) {
        for (int j=0; j<10-1; j++) {
            if (a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    for (int i=0; i<10; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
