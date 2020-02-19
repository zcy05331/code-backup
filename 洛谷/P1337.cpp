#include <bits/stdc++.h>
const int MaxN = 1010;
const double delta = 0.993;
struct node
{
    int x, y, w;
};
int n;
node a[MaxN];
double ansx, ansy;
double ans = 1e18, t;
inline int read()
{
    bool f = 0;
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = true;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    return (!f) ? x : -x;
}
double calc(double nx, double ny)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        double x = nx - a[i].x;
        double y = ny - a[i].y;
        sum += sqrt(x * x + y * y) * a[i].w;
    }
    return sum;
}
void sa()
{
    double nowx = ansx, nowy = ansy;
    t = 1000000;
    while (t > 1e-14)
    {
        double tmpx = ansx + (rand() * 2 - RAND_MAX) * t;
        double tmpy = ansy + (rand() * 2 - RAND_MAX) * t;
        double tmp = calc(tmpx, tmpy);
        if (tmp - ans < 0)
        {
            nowx = tmpx;
            nowy = tmpy;
            ansx = tmpx;
            ansy = tmpy;
            ans = tmp;
        }
        else if (exp((ans - tmp) / t) * RAND_MAX > rand())
        {
            nowx = tmpx;
            nowy = tmpy;
        }
        t *= delta;
    }
}
int main()
{
    n = read();
    srand(19260817);
    for (int i = 1; i <= n; i++)
        a[i].x = read(), a[i].y = read(), a[i].w = read();
    sa();
    printf("%.3lf %.3lf", ansx, ansy);
    return 0;
}
