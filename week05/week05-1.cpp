#include <cstdio>

int a[10] = {7,8,9, 1,2,3, 6,5,4, 0};

int main() {
    for (int i=0; i<10; i++) {
        for (int j=i+1; j<10; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    for (int i=0; i<10; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
