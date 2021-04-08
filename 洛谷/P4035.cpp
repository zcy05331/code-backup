#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 2e2 + 10;
const double eps = 1e-8;

int n; double x[MaxN][MaxN];
std::vector<std::vector<double> > a;

double sqr(double x) { return x * x; }

int check(double x)
{
    if(x > eps) return 1;
    else if(x < -eps) return -1;
    else return 0;
}

void gauss()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
            if(check(a[j][i]))
                std::swap(a[i], a[j]);
        if (check(a[i][i]) == 0)
            return (void)puts("No Solution");
        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            double rate = a[j][i] / a[i][i];
            for(int k = i; k <= n + 1; k++)
                a[j][k] -= a[i][k] * rate;
        }
    }
}

signed main()
{   
    scanf("%d", &n), a.resize(n + 1);
    for(int i = 1; i <= n; i++)
        a[i].resize(n + 2);
    for(int i = 1; i <= n + 1; i++)
    {
        for(int j = 1; j <= n; j++)
            std::cin >> x[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            a[i][j] = 2 * (x[i][j] - x[i + 1][j]);
        for(int j = 1; j <= n; j++)
            a[i][n + 1] += sqr(x[i][j]) - sqr(x[i + 1][j]);
    }
    gauss();
    for(int i = 1; i <= n; i++)
        printf("%.3lf ", a[i][n + 1] / a[i][i]);
    return 0;
}
