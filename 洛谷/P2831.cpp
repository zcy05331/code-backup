#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 20;
const double eps = 1e-8;

int n, m;
double x[20], y[20];
int line[MaxN][MaxN], lowbit[1 << MaxN], f[1 << MaxN];

void prework()
{
    for (int i = 0; i < (1 << 18); i++)
    {
        int j = 1;
        while ((j <= 18) && (i & (1 << (j - 1))))
            j++;
        lowbit[i] = j;
    }
}

void init()
{
    memset(line, 0, sizeof(line));
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
}

#define D double
void calc(D &x, D &y, D a1, D b1, D c1, D a2, D b2, D c2)
{
    y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
    x = (c1 - b1 * y) / a1;
}
#undef D

int main()
{

    int T;
    scanf("%d", &T), prework();
    while (T--)
    {
        init();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &x[i], &y[i]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (fabs(x[i] - x[j]) < eps)
                    continue;
                double a, b;
                calc(a, b, x[i] * x[i], x[i], y[i], x[j] * x[j], x[j], y[j]);
                if (a > -eps)
                    continue;
                for (int k = 1; k <= n; k++)
                    if (fabs(a * x[k] * x[k] + b * x[k] - y[k]) < eps)
                        line[i][j] |= (1 << (k - 1));
            }
        }
        for (int i = 0; i < (1 << n); i++)
        {
            int j = lowbit[i];
            f[i | (1 << (j - 1))] = std::min(f[i | (1 << (j - 1))], f[i] + 1);
            for (int k = 1; k <= n; k++)
                f[i | line[j][k]] = std::min(f[i | line[j][k]], f[i] + 1);
        }
        printf("%d\n", f[(1 << n) - 1]);
    }
    return 0;
}
