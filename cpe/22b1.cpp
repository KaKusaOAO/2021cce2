#include <cstdio>

int main()
{
    while (true) {
        int s;
        scanf("%d", &s);
        if (s == 0) break;
        
        int sum = 0, n = 1;
        for (; sum <= s; n++) sum += n;
        
        printf("%d %d\n", sum - s, n-1);
    }

    return 0;
}
