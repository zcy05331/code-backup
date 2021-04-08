#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 4e6 + 10;
const double pi = acos(-1.0);

struct comp
{
    double r, i;
    comp(double r_ = 0, double i_ = 0) : r(r_), i(i_) {}
    comp operator+(comp x) { return (comp){r + x.r, i + x.i}; }
    comp operator-(comp x) { return (comp){r - x.r, i - x.i}; }
    comp operator*(comp x) { return (comp){r * x.r - i * x.i, r * x.i + i * x.r}; }
};

comp a[MaxN], b[MaxN];
int n, m, l, lim = 1, r[MaxN];

void fft(comp *a, int flag)
{
    for (int i = 0; i < lim; i++)
        if (i < r[i])
            std::swap(a[i], a[r[i]]);
    for (int i = 1; i < lim; i <<= 1)
    {
        comp w(cos(pi / i), flag * sin(pi / i));
        for (int k = 0; k < lim; k += (i << 1))
        {
            comp t(1, 0);
            for (int l = 0; l < i; l++, t = t * w)
            {
                comp nx = a[k + l], ny = t * a[k + i + l];
                a[k + l] = nx + ny, a[k + l + i] = nx - ny;
            }
        }
    }
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

int main()
{
    n = read(), m = read();
    for (int i = 0; i <= n; i++)
        a[i].r = read();
    for (int i = 0; i <= m; i++)
        b[i].r = read();
    while (lim <= n + m)
        lim <<= 1, ++l;
    for (int i = 0; i < lim; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    fft(a, 1), fft(b, 1);
    for (int i = 0; i <= lim; i++)
        a[i] = a[i] * b[i];
    fft(a, -1);
    for (int i = 0; i <= n + m; i++)
        printf("%d ", (int)(a[i].r / lim + 0.5));
    return 0;
}