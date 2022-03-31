#include <cstdio>
#include <cstring>
#include <cstdlib>

int index(size_t size, int x, int y) {
    return (int)((y * size) + x);
}

void copyFromOrigin(int *matrix, size_t size, int w, int h, int x2, int y2) {
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            int idxA = index(size, x, y);
            int idxB = index(size, x + x2, y + y2);
            matrix[idxB] = matrix[idxA];
        }
    }
}

void evolve(int *matrix, size_t size, int nHour) {
    if (nHour == 0) {
        matrix[0] = 1;
        return;
    }

    int cSize = 1 << (nHour - 1);
    copyFromOrigin(matrix, size, cSize, cSize, cSize, 0);
    copyFromOrigin(matrix, size, cSize, cSize, 0, cSize);
}

void doTestCase(int t) {
    int hour;
    size_t size;
    scanf("%d", &hour);
    size = 1 << hour;

    size_t memSize = (size * size) * sizeof(int);
    int *matrix = (int*) malloc(memSize);
    memset(matrix, 0, memSize);

    for (int i=0; i<=hour; i++) {
        evolve(matrix, size, i);
    }

    int a, b, c = 0;
    scanf("%d %d", &a, &b);
    for (int i=a-1; i<=b-1; i++) {
        for (int j=0; j<size; j++) {
            int idx = index(size, j, i);
            if (matrix[idx] == 1) c++;
        }
    }

    printf("Case %d: %d\n", t, c);
    free(matrix);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        doTestCase(t);
    }

    return 0;
}
