#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int mod = 1e9 + 7;

struct matrix
{
    int n, m;
    int a[10][10];
    matrix(int x, int y)
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
            for (int k = 1; k <= b.n; k++)
                c.a[i][j] = sum(c.a[i][j], 1ll * a.a[i][k] * b.a[k][j], mod);
    return c;
}

matrix pow_(matrix a, ll b)
{
    matrix ret = a;
    if (b == 0)
        return a;
    --b;
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
    matrix ret(6, 6);
    ret.a[1][1] = 1, ret.a[1][2] = 1, ret.a[1][3] = 1, ret.a[1][4] = 4, ret.a[1][5] = 6, ret.a[1][6] = 4;
    ret.a[2][1] = 1, ret.a[3][3] = 1, ret.a[3][4] = 3, ret.a[3][5] = 3, ret.a[3][6] = 1;
    ret.a[4][4] = 1, ret.a[4][5] = 2, ret.a[4][6] = 1, ret.a[5][5] = 1, ret.a[5][6] = 1, ret.a[6][6] = 1;
    return ret;
}

matrix init_()
{
    matrix ret(6, 1);
    ret.a[1][1] = ret.a[3][1] = ret.a[4][1] = ret.a[5][1] = ret.a[6][1] = 1;
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    matrix a = init();
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        if (n == 0)
        {
            printf("0\n");
            continue;
        }
        if (n == 1)
        {
            printf("1\n");
            continue;
        }
        matrix c = pow_(a, n - 1);
        printf("%lld\n", (ll)(0ll + c.a[1][1] + c.a[1][3] + c.a[1][4] + c.a[1][5] + c.a[1][6] + mod) % mod);
    }
    return 0;
}
