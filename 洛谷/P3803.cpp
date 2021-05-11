#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 3e6 + 10;
const double pi = acos(-1.0);

struct comp
{
    double r, i;
    comp operator+(comp a) { return (comp){r + a.r, i + a.i}; }
    comp operator-(comp a) { return (comp){r - a.r, i - a.i}; }
    comp operator*(comp a) { return (comp){r * a.r - i * a.i, r * a.i + a.r * i}; }

};

comp a[MaxN], b[MaxN];
int n, m, l, lim = 1, r[MaxN];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

void fft(comp *a, int lim, int flag)
{
    for(int i = 0; i < lim; i++)
        if(i < r[i]) std::swap(a[i], a[r[i]]);
    for(int i = 1; i < lim; i <<= 1)
    {
        comp w = (comp){cos(pi / i), flag * sin(pi / i)};
        for(int j = 0; j < lim; j += (i << 1))
        {
            comp t = (comp) {1, 0};
            for(int k = 0; k < i; k++, t = t * w)
            {
                comp nx = a[j + k], ny = t * a[i + j + k];
                a[j + k] = nx + ny, a[i + j + k] = nx - ny;
            }
        }
    }
    if(flag == -1)
    {
        for(int i = 0; i < lim; i++)
            a[i].r = a[i].r / lim + 0.01;
    }
}

signed main()
{
    n = read(), m = read();
    while(lim <= m + n) lim <<= 1, ++l;
    for(int i = 0; i < lim; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    for(int i = 0; i <= n; i++) a[i].r = read();
    for(int i = 0; i <= m; i++) b[i].r = read();
    fft(a, lim, 1), fft(b, lim, 1);
    for(int i = 0; i < lim; i++)
        a[i] = a[i] * b[i];
    fft(a, lim, -1);
    for(int i = 0; i <= n + m; i++)
        printf("%d ", (int)a[i].r);
    return 0;
}
