#include <bits/stdc++.h>

#define R register
#define ll unsigned long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int base = 3331;
const int mod = 1e9 + 7;
const int MaxN = 3e5 + 10;

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

char s[MaxN];
int n, u[MaxN], v[MaxN];
mod_t h[MaxN], powm[MaxN];

int calc(int l, int r) { return (h[l] - h[r + 1] * powm[r - l + 1]).x; }

void init()
{
    n = 0, powm[0] = 1;
    memset(h, 0, sizeof(h));
    memset(u, 0, sizeof(u));
    memset(v, 0, sizeof(v));
    memset(s, 0, sizeof(s));
}

int suffix(int x, int y)
{
    if (s[x] != s[y]) return 0;
    int l = 1, r = std::min(n - x + 1, n - y + 1);
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (calc(x, x + mid - 1) == calc(y, y + mid - 1))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int prefix(int x, int y)
{
    if (s[x] != s[y]) return 0;
    int l = 1, r = std::min(x, y);
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (calc(x - mid + 1, x) == calc(y - mid + 1, y))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%s", s + 1), n = strlen(s + 1);
        for (int i = 1; i <= n; i++)
            powm[i] = powm[i - 1] * base;
        for (int i = n; i; i--)
            h[i] = (h[i + 1] * base + s[i]);
        for (int i = 1; i <= n >> 1; i++)
        {
            for (int j = 1; j + i <= n; j += i)
            {
                int x = j, y = j + i;
                int lcp = std::min(prefix(x, y), i);
                int lcs = std::min(suffix(x, y), i);
                // printf("%d %d %d %d\n", x, y, lcs, lcp);
                if (lcs + lcp > i)
                {
                    int len = lcp + lcs - i;
                    u[y + lcs - len]++, u[y + lcs]--;
                    v[x - lcp + 1]++, v[x - lcp + 1 + len]--;
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            u[i] += u[i - 1], v[i] += v[i - 1];
        for (int i = 1; i < n; i++)
            ans += u[i] * v[i + 1];
        printf("%lld\n", ans);
    }
    return 0;
}
