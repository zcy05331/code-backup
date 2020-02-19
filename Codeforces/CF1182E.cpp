#include <bits/stdc++.h>

#define R register
#define ll unsigned long long
#define sum(a, b, mod) ((a + b) % mod)

const ll mod = 1e9 + 7, mode = 1e9 + 6;

ll fast_mul(ll a, ll b, ll mod)
{
    ll ans = 0;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ans;
}

ll fast_pow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = fast_mul(ret, a, mod) % mod;
        a = fast_mul(a, a, mod) % mod;
        b >>= 1;
    }
    return ret;
}

struct matrix
{
    ll n, m, a[10][10];
    matrix(ll x, ll y)
    {
        n = x, m = y;
        memset(a, 0, sizeof(a));
    }
};

matrix mul(matrix a, matrix b)
{
    ll n = a.n, m = a.m, k = b.m;
    matrix c(n, k);
    for (ll i = 1; i <= n; i++)
        for (ll l = 1; l <= k; l++)
            for (ll j = 1; j <= m; j++)
                c.a[i][j] = (c.a[i][j] + fast_mul(a.a[i][l], b.a[l][j], mode)) % mode;
    return c;
}
matrix pow_(matrix a, ll b)
{
    matrix ret = a;
    while (b)
    {
        if (b & 1ll)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1ll;
    }
    return ret;
}

inline matrix init()
{
    matrix a(3, 3);
    a.a[1][1] = a.a[1][3] = a.a[2][1] = a.a[3][1] = a.a[3][2] = 1;
    return a;
}

inline matrix init_()
{
    matrix a(3, 1);
    a.a[1][1] = a.a[2][1] = a.a[3][1] = 1;
    return a;
}

int main()
{
    ll f[4], n, c;
    std::cin >> n >> f[1] >> f[2] >> f[3] >> c;
    matrix a = init(), b = init_(), x = pow_(a, n - 4), y = pow_(a, n - 4), z = pow_(a, n - 5);
    x = mul(x, b), y = mul(y, b), z = mul(z, b); // print(x), print(y), print(z);
    ll A = x.a[1][1], B = y.a[3][1], C = z.a[1][1], X = fast_mul(f[3], fast_pow(c, 3), mod), Y = fast_mul(f[2], fast_pow(c, 2), mod), Z = fast_mul(f[1], c, mod);
    // std::cout << A << ' ' << B << ' ' << C << '\n';
    // std::cout << X << ' ' << Y << ' ' << Z << '\n';
    ll ans = fast_mul(fast_mul(fast_mul(fast_pow(X, A), fast_pow(Y, B), mod), fast_pow(Z, C), mod), fast_pow(fast_pow(c, n), mod - 2llu), mod);
    std::cout << ans;
    return 0;
}
