#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int g = 3;
const int MaxN = 3e5 + 10;
const int mod = 998244353;
const int ginv = 332748118;

int n, m, l, lim = 1, a[MaxN], b[MaxN], r[MaxN];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int fast_pow(int a, int b)
{
    int ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * 1ll * a % mod;
        a = a * 1ll * a % mod;
        b >>= 1;
    }
    return ret;
}

void ntt(int *a, int flag)
{
    for (int i = 0; i < lim; i++)
        if (i < r[i])
            std::swap(a[i], a[r[i]]);
    for (int i = 1; i < lim; i <<= 1)
    {
        int w = fast_pow((~flag) ? g : ginv, (mod - 1) / (2 * i));
        for (int j = 0; j < lim; j += (i << 1))
        {
            int t = 1;
            for (int k = 0; k < i; k++, t = t * 1ll * w % mod)
            {
                int nx = a[j + k], ny = 1ll * t * a[i + j + k] % mod;
                meow("$ %d %d\n", nx, ny);
                a[j + k] = (nx + ny) % mod, a[j + k + i] = (nx - ny + mod) % mod;
            }
        }
    }
    // for (int i = 0; i < lim; i++)
    //     meow("%d ", a[i]); puts("");
}

int main()
{
    n = read(), m = read();
    for (int i = 0; i <= n; i++)
        a[i] = (read() + mod) % mod;
    for (int i = 0; i <= m; i++)
        b[i] = (read() + mod) % mod;
    while (lim <= m + n)
        lim <<= 1, ++l;
    for (int i = 0; i < lim; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    ntt(a, 1), ntt(b, 1);
    for (int i = 0; i < lim; i++)
        a[i] = a[i] * 1ll * b[i] % mod;
    ntt(a, -1);
    ll inv = fast_pow(lim, mod - 2);
    for (int i = 0; i <= n + m; i++)
        printf("%d ", (a[i] * 1ll * inv) % mod);
    return 0;
}
