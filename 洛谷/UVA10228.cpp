#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
const int MaxN = 200;
const double delta = 0.995;
int n;
int x[MaxN], y[MaxN];
double ansx, ansy;
inline double calc(double nx, double ny)
{
    double tmp = 0;
    for (int i = 1; i <= n; i++)
        tmp += sqrt((nx - x[i]) * (nx - x[i]) + (ny - y[i]) * (ny - y[i]));
    return tmp;
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
inline void sa()
{
    double t = 10000000;
    while (t > 1e-14)
    {
        double nowx = ansx + (rand() * 2 - RAND_MAX) * t;
        double nowy = ansy + (rand() * 2 - RAND_MAX) * t;
        double tmp = calc(nowx, nowy) - calc(ansx, ansy);
        if (tmp < 0)
            ansx = nowx, ansy = nowy;
        else if (exp(-tmp / t) * RAND_MAX > rand())
            ansx = nowx, ansy = nowy;
        t *= delta;
    }
}
int main()
{
    srand(time(NULL));
    int T = read();
    while (T--)
    {
        ansx = ansy = 0;
        n = read();
        for (int i = 1; i <= n; i++)
            x[i] = read(), y[i] = read();
        for (int i = 1; i <= 100; i++)
            sa();
        printf("%.0lf\n", calc(ansx, ansy));
        if(T)
            printf("\n");
    }
    return 0;
}
