#include <cstdio>

unsigned long long stepsO(int x, int y) {
    if (x == 0 && y == 0) return 0;
    int ty = x + y;
    int nx = ty - 1;
    unsigned long long result = x + 1;
    for (int i=1; i<=nx; i++) result += i+1;
    
    return result;
}

unsigned long long steps(int x1, int y1, int x2, int y2) {
    return stepsO(x2, y2) - stepsO(x1, y1);
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i=1; i<=n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("Case %d: %llu\n", i, steps(x1, y1, x2, y2));
    }
}