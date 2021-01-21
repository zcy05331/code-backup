#include <bits/stdc++.h>
using namespace std;
#define re unsigned
const int B = 400;
int n, m, a[100002], f[402][100002], g[402], bl[100002], st[100002], ed[100002], d[100002], b[402][402], p[402][402], s[402][402], c[402], len[402], f1[402][100002], h[402][402];
long long la;
inline int read()
{
    re long long t = 0;
    re char v = getchar();
    while (v < '0')
        v = getchar();
    while (v >= '0')
        t = (t << 3) + (t << 1) + v - 48, v = getchar();
    return t;
}
inline void add(re int x)
{
    for (re int i = bl[x] + 1; i <= bl[n]; ++i)
        ++g[i];
    for (re int i = x + 1; i <= ed[bl[x]]; ++i)
        ++d[i];
}
inline int cmp(re int x, re int y) { return a[x] < a[y]; }
inline int ask(re int x) { return g[bl[x]] + d[x]; }
inline int ask(re int x, re int l1, re int r1, re int y, re int l2, re int r2)
{
    re int l = 1, r = 1, sum = 0, sr = 0;
    while (l <= len[x] && r <= len[y])
    {
        if (b[x][l] < l1 || b[x][l] > r1)
        {
            ++l;
            continue;
        }
        if (b[y][r] < l2 || b[y][r] > r2)
        {
            ++r;
            continue;
        }
        if (a[b[x][l]] < a[b[y][r]])
            ++l, sum += sr;
        else
            ++r, ++sr;
    }
    while (l <= len[x])
        if (b[x][l] >= l1 && b[x][l] <= r1)
            sum += sr, ++l;
        else
            ++l;
    return sum;
}
signed main()
{
    freopen("sqrt.in", "r", stdin);
    freopen("sqrt.out", "w", stdout);
    n = read(), m = read();
    for (re int i = 1; i <= n; ++i)
        a[i] = read(), bl[i] = (i - 1) / B + 1, ed[bl[i]] = i, (!st[bl[i]]) && (st[bl[i]] = i);
    for (re int i = 1; i <= bl[n]; ++i)
    {
        re int cnt = 0;
        memset(g, 0, sizeof(g)), memset(d, 0, sizeof(d)), len[i] = ed[i] - st[i] + 1;
        for (re int j = st[i]; j <= ed[i]; ++j)
            b[i][++cnt] = j, p[i][cnt] = p[i][cnt - 1] + cnt - 1 - ask(a[j]), add(a[j]);
        for (re int j = 1; j < st[i]; ++j)
            f[i][j] = f[i][j - 1] + ask(a[j]);
        memset(g, 0, sizeof(g)), memset(d, 0, sizeof(d)), cnt = 0;
        for (re int j = ed[i]; j >= st[i]; --j)
            ++cnt, s[i][cnt] = s[i][cnt - 1] + ask(a[j]), add(a[j]);
        for (re int j = n; j > ed[i]; --j)
            f1[i][j] = f1[i][j + 1] + len[i] - ask(a[j]);
        sort(b[i] + 1, b[i] + cnt + 1, cmp), c[i] = s[i][len[i]];
        for (re int j = 1; j < i; ++j)
            for (re int k = st[j]; k <= ed[j]; ++k)
                h[j][i] += ask(a[k]);
    }
    for (re int i = 1; i <= bl[n]; ++i)
        for (re int j = bl[n]; j >= i; --j)
            h[i][j] += h[i][j + 1];
    while (m--)
    {
        re int l = read(), r = read(), x = bl[l], y = bl[r];
        if (x == y)
            printf("%lld\n", la = p[x][r - st[x] + 1] - p[x][l - st[x]] - ask(x, st[x], l - 1, x, l, r));
        else
        {
            la = s[x][ed[x] - l + 1] + p[y][r - st[y] + 1] + ask(x, l, ed[x], y, st[y], r);
            for (re int i = x + 1; i < y; ++i)
                la += c[i] + f[i][st[i] - 1] + f1[i][ed[i] + 1] - f[i][l - 1] - f1[i][r + 1] - h[i][i + 1] + h[i][y];
            printf("%lld\n", la);
        }
    }
    fprintf(stderr, "used %d ms\n", clock());
}