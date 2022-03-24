#include <cstdio>
#include <cstdlib>

int comparer(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int a[100];

    for (int i=0; i<100; i++) printf("%d ", a[i]);
    printf("\n");

    qsort(a, 100, sizeof(int), comparer);

    for (int i=0; i<100; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
