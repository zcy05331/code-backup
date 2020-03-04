#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e6 + 10;

int n, m;
int a[MaxN], rk[MaxN], sa[MaxN], buc[MaxN], old[MaxN];

int cmp(int x, int y, int w) { return (old[x] == old[y] && old[x + w] == old[y + w]); }

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

void SuffixSort()
{
    m = n;
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
        Sort(), std::swap(rk, old), rk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++)
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
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
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = a[i + n] = read();
    n <<= 1, SuffixSort();
    for (int i = 1; i <= n; i++)
    {
        if (sa[i] <= (n >> 1))
        {
            for (int j = 0; j < (n >> 1); j++)
                printf("%d ", a[sa[i] + j]);
            return 0;
        }
    }
    return 0;
}
