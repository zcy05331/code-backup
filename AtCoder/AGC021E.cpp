#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int mod = 998244353;
const int MaxN = 1e6 + 10;

struct mod_t
{
    int x;
    mod_t() {}
    mod_t(ll v) : x(v) {}
    mod_t(int v) : x(v) {}
    static int Mod(int x) { return ((x < 0) ? (x + mod) : x); }
    mod_t operator+(const mod_t y) const { return Mod(x + y.x - mod); }
    mod_t operator-(const mod_t y) const { return Mod(x - y.x); }
    mod_t operator*(const mod_t y) const { return (ll)x * y.x % mod; }
};

int n, k;
mod_t ans, fac[MaxN], inv[MaxN];

mod_t fast_pow(mod_t a, int b)
{
    mod_t ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a;
        a = a * a, b >>= 1;
    }
    return ret;
}

void prework(int n)
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i;
    inv[n] = fast_pow(fac[n], mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1);
}

mod_t C(int n, int m)
{
    if (m > n || m < 0) return 0;
    return (fac[n] * inv[m] * inv[n - m]).x;
}

int main()
{
    prework(1000000);
    scanf("%d%d", &n, &k);
    if (k < n) return 0 * printf("0");
    for (int i = 0; i <= k; i++)
    {
        int r = i, b = k - r;
        if(r < b) continue; if(r == b) --b;
        ans = ans + C(r + b, r) - C(r + b, 2 * r - n + 1);
    }
    printf("%d\n", ans.x);
    return 0;
}
