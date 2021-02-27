#include <bits/stdc++.h>

#define R register
#define sqr(x) ((x) * (x))
#define ll unsigned long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int G = 3;
const int MaxN = 5e5 + 10;
const int mod = 998244353;

int n, m, lim, w[MaxN], rev[MaxN], _inv[MaxN];

void Mod(int &x) { x += x >> 31 & mod; }

void __init()
{
    _inv[1] = 1;
    for (int i = 2; i < MaxN; i++)
        _inv[i] = (ll)(mod - mod / i) * _inv[mod % i] % mod;
}

int fast_pow(int a, int b)
{
    int ret = 1;
    while (b)
    {
        if (b & 1)
            ret = (ll)ret * a % mod;
        a = (ll)a * a % mod, b >>= 1;
    }
    return ret;
}

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

void init(int n)
{
    int l = 32 - __builtin_clz(n - 1);
    lim = (1 << l);
    for (int i = 0, ri = 0; i < lim; i++)
    {
        rev[i] = ri;
        for (int k = lim >> 1; (ri ^= k) < k;)
            k >>= 1;
    }
    int wn = fast_pow(G, (mod - 1) >> l);
    w[lim >> 1] = 1;
    for (int i = (lim >> 1) + 1; i < lim; i++)
        w[i] = (ll)w[i - 1] * wn % mod;
    for (int i = (lim >> 1) - 1; i; --i)
        w[i] = w[i << 1];
    lim = l;
}

struct poly
{
    std::vector<int> v;

    inline poly() {}
    inline poly(int n) : v(n) {}
    inline poly(const poly &r) : v(r.v) {}
    inline poly(const std::vector<int> &r) : v(r) {}

    inline size_t size() { return v.size(); }
    inline bool empty() { return v.empty(); }
    inline void resize(int n) { v.resize(n); }
    inline void clear() { v.clear(); }
    inline void shl() { v.insert(v.begin(), 0); }
    void shrink()
    {
        while (!v.empty() && !v.back())
            v.pop_back();
    }

    inline int &operator[](int i) { return v[i]; }
    inline static int len(int n) { return 1 << (32 - __builtin_clz(n - 1)); }

    void deriv()
    {
        for (int i = 1; i < v.size(); i++)
            v[i - 1] = (ll)i * v[i] % mod;
        v.pop_back();
    }
    void intg()
    {
        shl();
        for (int i = 1; i < v.size(); i++)
            v[i] = (ll)v[i] * _inv[i] % mod;
    }

    void dft(int n)
    {
        static ll tmp[MaxN];
        int ofs = lim - __builtin_ctz(n);
        resize(n);
        if (n <= 1) return;
        for (int i = 0; i < n; i++)
            tmp[rev[i] >> ofs] = v[i];
        for (int i = 0; i < n; i += 2)
        {
            int x = tmp[i], y = tmp[i + 1];
            tmp[i] = x + y, tmp[i + 1] = x + mod - y;
        }
        for (int i = 2; i < n; i <<= 1)
            for (int j = 0; j < n; j += (i << 1))
                for (int k = 0; k < i; ++k)
                {
                    int y = (ll)tmp[i + j + k] * w[i + k] % mod;
                    tmp[i + j + k] = tmp[j + k] + mod - y, tmp[j + k] += y;
                }
        for (int i = 0; i < n; i++)
            v[i] = tmp[i] % mod;
    }
    void idft(int n)
    {
        dft(n);
        if (n <= 1) return;
        std::reverse(v.begin() + 1, v.end());
        int tmp = mod - (mod - 1) / n;
        for (int i = 0; i < n; i++)
            v[i] = (ll)v[i] * tmp % mod;
    }
    void mul(poly r)
    {
        int n = len(size() + r.size() - 1);
        dft(n), r.dft(n);
        for (int i = 0; i < n; i++)
            v[i] = (ll)v[i] * r[i] % mod;
        idft(n), shrink();
    }
    void inv()
    {
        std::vector<int> va(1);
        int n = size(), m = len(n);
        va[0] = fast_pow(v[0], mod - 2);
        poly a;
        v.resize(m), v.swap(va);
        for (int i = 2; i <= m; i <<= 1)
        {
            a.resize(i);
            for (int j = 0; j < i; j++)
                a[j] = va[j];
            a.dft(i << 1), dft(i << 1);
            for (int j = 0; j < (i << 1); j++)
                v[j] = v[j] * (2 + mod - (ll)v[j] * a[j] % mod) % mod;
            idft(i << 1), resize(i);
        }
        resize(n);
    }
    void ln()
    {
        poly f0 = *this;
        int n = size();
        deriv(), f0.inv(), mul(f0);
        resize(n), intg(), resize(n);
    }
    void exp()
    {
        std::vector<int> va(1);
        va[0] = 1;
        poly a;
        int n = size(), m = len(n);
        v.resize(m), v.swap(va);
        for (int i = 2; i <= m; i *= 2)
        {
            a = *this, a.resize(i), a.ln();
            for (int j = 0; j < i; j++)
                a[j] = (va[j] + !j + mod - a[j]) % mod;
            mul(a), resize(i);
        }
        resize(n);
    }
} a, b;

ll a1, a2, b1, b2, ans;

signed main()
{
    n = read(), __init(), init(n * 3);
    m = read(), a.resize(2 * n), b.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]), a[i + n] = a[i];
    for (int i = 0; i < n; i++)
        scanf("%d", &b[n - i - 1]);
    for (int i = 0; i < n; i++)
    {
        a1 += a[i], b1 += b[i];
        a2 += sqr(a[i]), b2 += sqr(b[i]);
    }
    a.mul(b), ans = 1e18 + 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = -m; j <= m; j++)
        {
            ll now = a2 + b2 + n * j * j + 2ll * j * (a1 - b1) - 2ll * a[i + n];
            ans = std::min(ans, now);
        }
    }
    printf("%lld\n", ans);
    return 0;
}