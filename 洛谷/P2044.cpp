#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define Add(a, b, mod) (a += b, (a >= mod) ? (a -= mod) : 0)

struct matrix
{
    ll n, m;
    ll a[3][3];
    matrix(int x = 0, int y = 0)
    {
        n = x, m = y;
        memset(a, 0, sizeof(a));
    }
};

ll n, m, a, c, g, x0;

ll fast_mul(ll a, ll b, ll m)
{
    ll d = ((long double)a / m * b + 1e-8);
    ll r = a * b - d * m;
    return r < 0 ? r + m : r;
}

matrix I()
{
    matrix i(2, 2);
    i.a[1][1] = 1, i.a[2][2] = 1;
    return i;
}

matrix init()
{
    matrix A(2, 2);
    A.a[1][1] = a, A.a[1][2] = c;
    A.a[2][1] = 0, A.a[2][2] = 1;
    return A;
}

matrix Init()
{
    matrix A(2, 1);
    A.a[1][1] = x0, A.a[2][1] = 1;
    return A;
}

matrix mul(matrix a, matrix b)

{
    matrix c(a.n, b.m);

    for (int i = 1; i <= a.n; i++)
        for (int j = 1; j <= b.m; j++)
            for (int k = 1; k <= a.m; k++)
                Add(c.a[i][j], fast_mul(a.a[i][k], b.a[k][j], m), m);
    return c;
}

matrix pow(matrix a, ll b)

{
    matrix ret = I();
    while (b)

    {
        if (b & 1) ret = mul(ret, a);
        a = mul(a, a), b >>= 1;
    }
    return ret;
}

int main()
{
    scanf("%lld%lld%lld%lld%lld%lld", &m, &a, &c, &x0, &n, &g);
    matrix a = Init(), b = pow(init(), n), c = mul(b, a);
    printf("%lld\n", c.a[1][1] % g);
    return 0;
}