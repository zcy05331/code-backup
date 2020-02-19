#include <bits/stdc++.h>
const int MaxN = 3e6 + 10;
const double pi = acos(-1.0);
struct p
{
    double x, y;
    p(double xx = 0, double yy = 0){x = xx, y = yy;}
};
int n, m;
p a[MaxN], b[MaxN];
int lim = 1, l, r[MaxN];
p operator*(p x, p y)
{
    return (p){x.x * y.x - x.y * y.y, x.x * y.y + x.y * y.x};
}
p operator+(p x, p y)
{
    return (p){x.x + y.x, x.y + y.y};
}
p operator-(p x, p y)
{
    return (p){x.x - y.x, x.y - y.y};
}
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch - 48), ch = getchar();
    return x;
}
inline void FFT(p *A, int flag)
{
    for (int i = 0; i < lim; i++)
        if (i < r[i])
            std::swap(A[i], A[r[i]]);
    for (int i = 1; i < lim; i <<= 1)
    {
        p T(cos(pi / i), flag * sin(pi / i));
        for(int k = 0; k < lim; k += (i << 1))
        {
            p t(1, 0);
            for(int l = 0; l < i; l++, t = t * T)
            {
                p nx = A[k + l], ny = t * A[k + i + l];
                A[k + l] = nx + ny;
                A[k + i + l] = nx - ny;
            }
        }
    }
}
int main()
{
    n = read(), m = read();
    for (int i = 0; i <= n; i++)
        a[i].x = read();
    for (int i = 0; i <= m; i++)
        b[i].x = read();
    while (lim <= n + m)
        lim <<= 1, ++l;
    for (int i = 0; i < lim; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    FFT(a, 1), FFT(b, 1);
    for (int i = 0; i <= lim; i++)
        a[i] = a[i] * b[i];
    FFT(a, -1);
    for (int i = 0; i <= n + m; i++)
        printf("%d ", (int)(a[i].x / lim + 0.5));
    return 0;
}
