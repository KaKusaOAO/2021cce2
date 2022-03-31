#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long ll;

bool isPowerOf2(ll n) {
    if (n == 0) return true;
    while ((n & 1) == 0) n >>= 1;
    return n == 1;
}

int getPowerOf2(ll n) {
    if (n <= 0) return 0;
    int m = 0;
    while (n != 1) {
        n >>= 1;
        m++;
    }
    return m;
}

ll getMaxPowerOf2BelowN(ll n) {
    if (n <= 0) return 0;
    return 1 << getPowerOf2(n);
}

ll getMinPowerOf2AboveN(ll n) {
    return getMaxPowerOf2BelowN(n) << 1;
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

ll rowCountBelowRow(ll row, ll size) {
    if (size == 2) {
        return 3 - row;
    }
    if (row > size) return 0;
    if (row == size) return 1;

    ll sum = 1;
    ll base = size - row + 1;
    for (ll i=0; i < getPowerOf2(base); i++) {
        sum *= 3;
    }

    if (row != 1) {
        ll newSize = size / 2;
        sum += rowCountBelowRow(row, newSize) * 2;
    }
    return sum;
}

void doTestCase(int t) {
    int k;
    ll a, b;
    scanf("%d %llu %llu", &k, &a, &b);
    if (k < 0) k = 0;
    if (k > 30) k = 30;

    ll size = 1 << k;
    ll result = rowCountBelowRow(a, size) - rowCountBelowRow(b + 1, size);
    printf("Case %d: %llu\n", t, result);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        doTestCase(t);
    }

    return 0;
}
