#include <bits/stdc++.h>

#define R register
#define ll unsigned long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int G = 3;
const int MaxK = 40001;
const int inv2 = 499122177;
const int MaxN = 6e5 + 10;
const int mod = 998244353;

int n, k, lim, w[MaxN], rev[MaxN], _inv[MaxN];

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
    void mul(int k)
    {
        int n = size();
        for (int i = 0; i < n; i++)
            v[i] = (ll)(v[i] * k % mod + mod) % mod;
    }
    void add(poly r)
    {
        int n = std::max(size(), r.size());
        resize(n);
        for (int i = 0; i < n; i++)
            v[i] = (ll)(v[i] + r[i]) % mod;
        shrink();
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
        for (int i = 1; i <= m; i <<= 1)
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
        for (int i = 1; i <= m; i *= 2)
        {
            a = *this, a.resize(i), a.ln();
            for (int j = 0; j < i; j++)
                a[j] = (va[j] + !j + mod - a[j]) % mod;
            mul(a), resize(i);
        }
        resize(n);
    }
    void pw(int k)
    {
        ln();
        int n = size();
        for (int i = 0; i < n; i++)
            v[i] = (ll)v[i] * k % mod;
        exp();
    }
    void pw1(int k)
    {
        int n = size(), m = len(n);
        poly a; a.v.clear(), a.v.push_back(1), v.swap(a.v);
        while (k)
        {
            if (k & 1) mul(a);
            a.mul(a), k >>= 1;
            resize(n), a.resize(n);
        }
    }
    void sqrt()
    {
        std::vector<int> va(1);
        int n = size(), m = len(n);
        poly a, b;
        va[0] = ::sqrt(v[0]);
        v.resize(m), v.swap(va);
        for (int i = 1; i <= m; i <<= 1)
        {
            a.resize(i), b.resize(i);
            for (int j = 0; j < i; j++)
                a[j] = va[j], b[j] = v[j];
            b.inv(), a.mul(b);
            for (int j = 0; j < i; j++)
                v[j] = (ll)(v[j] + a[j]) % mod * inv2 % mod;
            resize(i << 1);
        }
        resize(n);
    }
} f, g, h;

inline int read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = ((x * 10) + (ch ^ 48)), ch = getchar();
    return x;
}

signed main()
{
    int pw2 = 0;
    __init(), init(250000), n = read(), k = read();
    f.resize(MaxK), f[0] = 1, f[1] = 6, f[2] = 1;
    g = h = f, h.sqrt(), h[0]++, h[1]++, g.sqrt(), g.inv();
    h.pw1(n + 1), g.mul(h), pw2 = fast_pow(inv2, n + 1);
    for(int i = 1; i <= std::min(n, k); i++)
        printf("%d ", (ll)g[i] * pw2 % mod);
    for(int i = std::min(n, k) + 1; i <= k; i++)
        printf("%d ", 0);
    return 0;
}