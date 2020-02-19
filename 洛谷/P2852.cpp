#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1.5e6 + 10;

int n, m, k, l, r, ans;
int rk[MaxN], old[MaxN], buc[MaxN];
int q[MaxN], a[MaxN], h[MaxN], sa[MaxN];

int cmp(int x, int y, int w) { return (old[x] == old[y]) && (old[x + w] == old[y + w]); }

void Sort()
{
    for (int i = 0; i <= m; i++)
        buc[i] = 0;
    for (int i = 1; i <= n; i++)
        buc[rk[i]]++;
    for (int i = 1; i <= m; i++)
        buc[i] += buc[i - 1];
    for (int i = n; i; i--)
        sa[buc[rk[old[i]]]--] = old[i];
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

void SuffixSort()
{
    m = 1200000;
    for (int i = 1; i <= n; i++)
        rk[i] = a[i], old[i] = i;
    Sort();
    for (int w = 1, p = 0; p < n; m = p, w <<= 1)
    {
        p = 0;
        for (int i = 1; i <= w; i++)
            old[++p] = n - w + i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > w)
                old[++p] = sa[i] - w;
        Sort(), std::swap(old, rk), rk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++)
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    }
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (k)
            --k;
        while (a[i + k] == a[sa[rk[i] - 1] + k])
            ++k;
        h[rk[i]] = k;
    }
}

int main()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    SuffixSort(), l = 1, r = 0;
    for (int i = 1; i <= n; i++)
    {
        while (l <= r && q[l] <= i - k + 1)
            ++l;
        while (l <= r && h[i] <= h[q[r]])
            --r;
        q[++r] = i;
        if (i >= k)
            ans = std::max(ans, h[q[l]]);
    }
    printf("%d\n", ans);
    return 0;
}
