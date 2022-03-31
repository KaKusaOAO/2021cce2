#include <cstdio>
#include <cmath>

typedef long long ll;

ll powll(ll a, ll b) {
    int n = a;
    for (ll i=1; i<b; i++) {
        a *= n;
    }
    return a;
}

int powOf2(ll n) {
    if (n == 0) return 0;
    int m = 0;
    while (n != 1) {
        n >>= 1;
        m++;
    }
    return m;
}

ll getTotal(ll row) {
    // row: inversed!
    if (row <= 1) return row;

    ll p = powOf2(row);
    ll size = powll(2, p);
    ll result = powll(3, p);

    if (row - size > 0) {
        result += getTotal(row - size) * 2;
    }
    return result;
}

void swap(ll& a, ll& b) {
    ll tmp = a;
    a = b;
    b = tmp;
}

void doTestCase(int t) {
    int k;
    ll a, b;
    scanf("%d %llu %llu", &k, &a, &b);
    ll size = powll(2, k);

    a = size - a + 1;
    b = size - b;
    if (a < b) swap(a, b);

    printf("Case %d: %llu\n", t, getTotal(a) - getTotal(b));
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        doTestCase(t);
    }
    return 0;
}
