#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

char s[MaxN];
int n, m, rk[MaxN], sa[MaxN], buc[MaxN], old[MaxN];

int cmp(int x, int y, int w){return (old[x] == old[y]) && (old[x + w] == old[y + w]);}

void sort_()
{
    for(int i = 0; i <= m; i++)
        buc[i] = 0;
    for(int i = 1; i <= n; i++)
        buc[rk[i]]++;
    for(int i = 1; i <= m; i++)
        buc[i] += buc[i - 1];
    for(int i = n; i >= 1; i--)
        sa[buc[rk[old[i]]]--] = old[i];
}

void suffixsort()
{
    m = 300;
    for(int i = 1; i <= n; i++)
        rk[i] = s[i], old[i] = i;
    sort_();
    for(int w = 1, p = 0; p < n; m = p, w <<= 1)
    {
        p = 0;
        for(int i = 1; i <= w; i++)
            old[++p] = n - w + i;
        for(int i = 1; i <= n; i++)
            if(sa[i] > w)
                old[++p] = sa[i] - w;
        sort_(), std::swap(rk, old);
        rk[sa[1]] = p = 1;
        for(int i = 2; i <= n; i++)
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : (++p);
    }
}

int main()
{   
    scanf("%s", s + 1), n = strlen(s + 1), suffixsort();
    for(int i = 1; i <= n; i++)
        printf("%d ", sa[i]);
    return 0;
}
