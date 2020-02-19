#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 6e3 + 10;

char s[MaxN];
int n, m, h[MaxN], sa[MaxN], rk[MaxN], buc[MaxN], old[MaxN];

int cmp(int x, int y, int w) { return (old[x] == old[y] && old[x + w] == old[y + w]); }

void init()
{
    memset(h, 0, sizeof(h));
    memset(sa, 0, sizeof(sa));
    memset(rk, 0, sizeof(rk));
}

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
    m = 150;
    for (int i = 1; i <= n; i++)
        rk[i] = s[i], old[i] = i;
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
        while (s[i + k] == s[sa[rk[i] - 1] + k])
            ++k;
        h[rk[i]] = k;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init(), scanf("%s", s + 1);
        n = strlen(s + 1), SuffixSort();
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = std::max(ans, h[i]);
        printf("%d\n", ans);
    }
    return 0;
}
