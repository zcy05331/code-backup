#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 3e6 + 10;

int n, p;
int inv[MaxN];

int main()
{
    scanf("%d%d", &n, &p);
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (ll)(p - p / i) * inv[p % i] % p;
    for (int i = 1; i <= n; i++)
        printf("%d\n", inv[i]);
    return 0;
}
