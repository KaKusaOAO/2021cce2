#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef long long u64;

void advcoef(u64 *coefficients, int count, u64 c) {
    u64 tmp[count + 1];
    memset(tmp, 0, sizeof(u64) * (count + 1));
    for (int i=0; i<count; i++) {
        tmp[i] += coefficients[i];
        tmp[i+1] = coefficients[i] * c;
    }
    memcpy(coefficients, tmp, sizeof(u64) * (count + 1));
}

u64 abs(u64 n) {
    return n > 0 ? n : -n;
}

bool isNeg(u64 n) {
    return n < 0;
}

int main() {
    while (true) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        
        u64 roots[n], coefficients[n];
        memset(roots, 0, n * sizeof(u64));
        memset(coefficients, 0, n * sizeof(u64));
        
        for (int i=0; i<n; i++) {
            scanf("%lld", &roots[i]);
        }
        
        coefficients[0] = 1;
        coefficients[1] = -roots[0];
        
        int cCount = 2;
        for (int i=1; i<n; i++) {
            advcoef(coefficients, cCount++, -roots[i]);	
        }
        
        for (int i=0; i<cCount; i++) {
            int xp = n - i;
            u64 c = coefficients[i];
            if (i == 0) {
                if (xp > 1) {
                    printf("x^%d ", xp);
                } else if (xp == 1) {
                    printf("x ");
                }
            } else {
                if (c == 0 && xp > 0) continue;
                if (abs(c) == 1) {
                    printf("%c ", isNeg(c) ? '-' : '+');
                } else {
                    printf("%c %lld", isNeg(c) ? '-' : '+', abs(c));
                }
                
                if (xp > 1) {
                    printf("x^%d", xp);
                } else if (xp == 1) {
                    printf("x");
                }
                printf(" ");
            }
        }
        printf("= 0\n");
    }
}