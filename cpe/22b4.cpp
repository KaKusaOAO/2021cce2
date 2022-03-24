#include <cstdio>
#include <cstdlib>
#include <cstring>

int index(int size, int x, int y) {
    return size * y + x;
}

void row(int *matrix, int size, int a, int b) {
    int tmp[size];
    a--; b--;
    for (int i=0; i<size; i++) {
        tmp[i] = matrix[index(size, i, a)];
    }
    for (int i=0; i<size; i++) {
        int aIdx = index(size, i, a);
        int bIdx = index(size, i, b);
        matrix[aIdx] = matrix[bIdx];
        matrix[bIdx] = tmp[i];
    }
}

void col(int *matrix, int size, int a, int b) {
    int tmp[size];
    a--; b--;
    for (int i=0; i<size; i++) {
        tmp[i] = matrix[index(size, a, i)];
    }
    for (int i=0; i<size; i++) {
        int aIdx = index(size, a, i);
        int bIdx = index(size, b, i);
        matrix[aIdx] = matrix[bIdx];
        matrix[bIdx] = tmp[i];
    }
}

void inc(int *matrix, int size) {
    int c = size * size;
    for (int i=0; i<c; i++) {
        matrix[i] = (matrix[i]+1) % 10;
    }
}

void dec(int *matrix, int size) {
    int c = size * size;
    for (int i=0; i<c; i++) {
        int v = matrix[i]-1;
        if (v < 0) v += 10;
        matrix[i] = v;
    }
}

void transpose(int *matrix, int size) {
    int c = size * size;
    int *tmp = (int*) malloc(c*sizeof(int));
    memcpy(tmp, matrix, c * sizeof(int));
    
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            int idx = index(size, j, i);
            int tIdx = index(size, i, j);
            matrix[idx] = tmp[tIdx];
        }
    }
    
    free(tmp);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t=1; t<=T; t++) {
        int size;
        scanf("%d", &size);
        
        int matrix[size*size];
        for (int y=0; y<size; y++) {
            for (int x=0; x<size; x++) {
                int val;
                scanf("%1d", &val);
                matrix[index(size, x, y)] = val;
            }
        }
        
        int op;
        scanf("%d", &op);
        for (int oc=0; oc<op; oc++) {
            char inst[256];
            scanf("%s", inst);
            
            if (strcmp(inst, "row") == 0) {
                int a, b;
                scanf("%d %d", &a, &b);
                row(matrix, size, a, b);
            } else if (strcmp(inst, "col") == 0) {
                int a, b;
                scanf("%d %d", &a, &b);
                col(matrix, size, a, b);
            } else if (strcmp(inst, "inc") == 0) {
                inc(matrix, size);
            } else if (strcmp(inst, "dec") == 0) {
                dec(matrix, size);
            } else if (strcmp(inst, "transpose") == 0) {
                transpose(matrix, size);
            }
        }
        
        printf("Case #%d\n", t);
        for (int y=0; y<size; y++) {
            for (int x=0; x<size; x++) {
                printf("%d", matrix[index(size, x, y)]);
            }
            printf("\n");
        }
        printf("\n");
    }
}