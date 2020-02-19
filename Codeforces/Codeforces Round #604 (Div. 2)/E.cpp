#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int mod = 998244353;
const int MaxN = 2e5 + 10;

int n, a[MaxN];

int fast_pow(int a, int b)
{
    int ret = 1;
    while (b)
    {
        if (b & 1)
            ret = (ret * 1ll * a) % mod;
        a = (a * 1ll * a) % mod;
        b >>= 1;
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = 0, tmp = 1;
    for (int i = n; i; i--)
    {
        tmp = ((tmp * 100ll % mod) * fast_pow(a[i], mod - 2ll)) % mod;
        ans = sum(ans, tmp, mod);
    }
    printf("%d\n", ans % mod);
    return 0;
}
