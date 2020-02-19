#include <bits/stdc++.h>
const int MaxN = 50;
const double delta = 0.995;
int n, m;
int a[MaxN], f[MaxN];
double sum[MaxN], aver = 0, ans = 1e18;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0')
    {
        if(ch == '-')
            f = 0;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}
inline double calc()
{
    double tmp = 0;
    for (int i = 1; i <= m; i++)
        tmp += (sum[i] - aver) * (sum[i] - aver);
    return tmp;
}
void sa()
{
    memset(sum, 0, sizeof(sum));
    double tmp = 0;
    for(int i = 1; i <= n; i++)
        f[i] = rand() % m + 1, sum[f[i]] += a[i];
    for(int i = 1; i <= m; i++)
        tmp += (sum[i] - aver) * (sum[i] - aver);
    double t = 10000000;
    while(t > 1e-14)
    {
        int x = rand() % n + 1, y = rand() % n + 1;
        while(f[x] == f[y])
            x = rand() % n + 1, y = rand() % n + 1;
        sum[f[x]] -= a[x];
        sum[f[x]] += a[y];
        sum[f[y]] += a[x];
        sum[f[y]] -= a[y];
        double now = calc();
        if ((now < tmp) || (exp((now - tmp) / t) * RAND_MAX < rand()))
            tmp = now, std::swap(f[x], f[y]);
        else
            sum[f[x]] += (a[x] - a[y]), sum[f[y]] += (a[y] - a[x]);        
        t *= delta;
    }
    if(tmp < ans)
        ans = tmp;
}
int main()
{   
    srand(time(NULL));
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        a[i] = read(), aver += a[i];
    aver /= m;
    for(int i = 1; i <= 500; i++)
        sa();
    printf("%.2lf", sqrt(ans / m));
    return 0;
}
