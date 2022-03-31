#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long ll;

bool isPowerOf2(ll n) {
    if (n == 0) return true;
    while ((n & 1) == 0) n >>= 1;
    return n == 1;
}

ll getMaxPowerOf2BelowN(ll n) {
    if (n == 0) return 0;

    int m = 0;
    while (n != 1) {
        n >>= 1;
        m++;
    }
    return 1 << m;
}

ll rowCount(ll row, ll size) {
    ll n = size - row + 1;
    if (isPowerOf2(n)) {
        return n;
    }

    ll a = getMaxPowerOf2BelowN(size-1);
    if (a >= 4) {
        ll r = row > a ? row - a : row;
        ll c = rowCount(r, a);
        return n < a ? c : c * 2;
    }

    switch (row) {
        case 1: return 4;
        case 2:
        case 3: return 2;
        case 4:
        default: return 1;
    }
}

void doTestCase(int t) {
    int k, a, b;
    scanf("%d %d %d", &k, &a, &b);

    ll sum = 0;
    ll size = 1 << k;
    for (ll i=a; i<=b; i++) {
        sum += rowCount(i, size);
    }
    printf("Case %d: %llu\n", t, sum);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        doTestCase(t);
    }

    return 0;
}
