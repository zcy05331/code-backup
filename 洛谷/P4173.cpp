#include <bits/stdc++.h>

#define R register
#define ll unsigned long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e6 + 10;
const double pi = acos(-1.0);

struct comp
{
    double r, i;
    comp(double r_ = 0, double i_ = 0) : r(r_), i(i_) {}
    comp operator+(comp x) { return (comp){r + x.r, i + x.i}; }
    comp operator-(comp x) { return (comp){r - x.r, i - x.i}; }
    comp operator*(comp x) { return (comp){r * x.r - i * x.i, r * x.i + i * x.r}; }
};

char s[MaxN], t[MaxN];
comp A[MaxN], B[MaxN], C[MaxN];
int n, m, l, lim = 1, r[MaxN], a[MaxN], b[MaxN];

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
    if (flag == -1)
        for (int i = 0; i < lim; i++)
            a[i].r = a[i].r / lim;
}

inline int read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = ((x * 10) + (ch ^ 48)), ch = getchar();
    return x;
}

std::vector<int> ans;

signed main()
{
    n = read(), m = read(), scanf("%s%s", s, t);
    while (lim < 2 * m)
        lim <<= 1, ++l;
    for (int i = 0; i < lim; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    for (int i = 0; i < n; i++)
        a[i] = ((s[i] == '*') ? 0 : (s[i] - 'a' + 1));
    for (int i = 0; i < m; i++)
        b[i] = ((t[i] == '*') ? 0 : (t[i] - 'a' + 1));
    std::reverse(a, a + n);

    for (int i = 0; i < lim; i++)
        A[i] = B[i] = comp(0, 0);
    for (int i = 0; i < n; i++)
        A[i].r = a[i] * a[i] * a[i], A[i].i = 0;
    for (int i = 0; i < m; i++)
        B[i].r = b[i], B[i].i = 0;
    fft(A, 1), fft(B, 1);
    for (int i = 0; i < lim; i++)
        C[i] = C[i] + A[i] * B[i];

    for (int i = 0; i < lim; i++)
        A[i] = B[i] = comp(0, 0);
    for (int i = 0; i < n; i++)
        A[i] = a[i] * a[i], A[i].i = 0;
    for (int i = 0; i < m; i++)
        B[i] = b[i] * b[i], B[i].i = 0;
    fft(A, 1), fft(B, 1);
    for (int i = 0; i < lim; i++)
        C[i] = C[i] - A[i] * B[i] - A[i] * B[i];

    for (int i = 0; i < lim; i++)
        A[i] = B[i] = comp(0, 0);
    for (int i = 0; i < n; i++)
        A[i] = a[i], A[i].i = 0;
    for (int i = 0; i < m; i++)
        B[i] = b[i] * b[i] * b[i], B[i].i = 0;
    fft(A, 1), fft(B, 1);
    for (int i = 0; i < lim; i++)
        C[i] = C[i] + A[i] * B[i];

    fft(C, -1);
    for (int i = n - 1; i < m; i++)
        if (fabs(C[i].r) < 1e-1) ans.push_back(i - n + 2);
    printf("%d\n", ans.size());
    for (auto x : ans)
        printf("%d ", x);
    return 0;
}