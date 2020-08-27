#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int base = 331;
const int mod = 998244353;
const int MaxN = 2e5 + 10;

struct mod_t
{
    int x;
    mod_t() {}
    mod_t(ll v) : x(v) {}
    mod_t(int v) : x(v) {}
    mod_t(long int v) : x(v) {}
    static int Mod(int x) { return ((x < 0) ? (x + mod) : x); }
    mod_t operator+(const mod_t y) const { return Mod(x + y.x - mod); }
    mod_t operator-(const mod_t y) const { return Mod(x - y.x); }
    mod_t operator*(const mod_t y) const { return (ll)x * y.x % mod; }
};

int n, ans;
char s[MaxN], t[MaxN];
mod_t a[MaxN], reva[MaxN], b[MaxN], revb[MaxN], powm[MaxN];

int gethash(int l, int r, mod_t a[]) { return (a[r] - a[l - 1] * powm[r - l + 1]).x;}

void prework()
{
    powm[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        powm[i] = powm[i - 1] * base;
        a[i] = a[i - 1] * base + s[i];
        b[i] = b[i - 1] * base + t[i];
    }
    std::reverse(s + 1, s + n + 1);
    std::reverse(t + 1, t + n + 1);
    for(int i = 1; i <= n; i++)
    {
        reva[i] = reva[i - 1] * base + s[i];
        revb[i] = revb[i - 1] * base + t[i];
    }
}

int main()
{
    scanf("%d%s%s", &n, s + 1, t + 1), prework();

    printf("%d\n", ans);
    return 0;
}
