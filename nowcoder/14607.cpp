#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int mod = 1000000009;

struct matrix
{
    ll n, m;
    ll a[10][10];
    matrix(ll x, ll y)
    {
        n = x, m = y;
        memset(a, 0, sizeof(a));
    }
};

matrix mul(matrix a, matrix b)
{
    matrix c(a.n, b.m);
    for (int i = 1; i <= a.n; i++)
        for (int j = 1; j <= b.m; j++)
            for (int k = 1; k <= a.m; k++)
                c.a[i][j] = sum(c.a[i][j], 1ll * a.a[i][k] * b.a[k][j], mod);
    return c;
}

matrix pow_(matrix a, ll b)
{
    b--;
    if (b <= 0)
        return a;
    matrix ret = a;
    while (b)
    {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

matrix init()
{
    matrix a(4, 4);
    a.a[1][1] = 2, a.a[1][2] = 1, a.a[1][3] = 2, a.a[1][4] = 1;
    a.a[2][2] = 1, a.a[2][3] = 2, a.a[2][4] = 1, a.a[3][3] = 1;
    a.a[3][4] = 1, a.a[4][4] = 1;
    return a;
}

matrix init_()
{
    matrix a(4, 1);
    a.a[4][1] = 1;
    return a;
}

int main()
{
    ll n;
    matrix a = init(), b = init_();
    while (scanf("%lld", &n) == 1)
    {
        matrix c = mul(pow_(a, n), b);
        if (n == 0)
        {
            printf("0\n");
            continue;
        }
        printf("%lld\n", c.a[1][1]);
    }
    return 0;
}
