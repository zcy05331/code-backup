#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

int n, m;
char s[MaxN];
int sa[MaxN], rk[MaxN], buc[MaxN], old[MaxN], ht[MaxN];

int cmp(int x, int y, int w) {return (old[x] == old[y]) && (old[x + w] == old[y + w]);}

void Sort()
{
    for(int i = 0; i <= m; i++) buc[i] = 0;
    for(int i = 1; i <= n; i++) buc[rk[i]]++;
    for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
    for(int i = n; i; i--) sa[buc[rk[old[i]]]--] = old[i];
}

void SuffixSort()
{
    m = 250;
    for(int i = 1; i <= n; i++) 
        rk[i] = s[i], old[i] = i;
    Sort();
    for(int w = 1, p = 0; p < n; m = p, w <<= 1)
    {
        p = 0;
        for(int i = 1; i <= w; i++)
            old[++p] = n - w + i;
        for(int i = 1; i <= n; i++)
            if(sa[i] > w) old[++p] = sa[i] - w;
        Sort(), std::swap(rk, old), rk[sa[1]] = p = 1;
        for(int i = 2; i <= n; i++)
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    }
    int k = 0;
    for(int i = 1; i <= n; i++)
    {
        if(k) k--;
        while(s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
        ht[rk[i]] = k;
    }
}

int main()
{   
    ll ans = 0;
    scanf("%d%s", &n, s + 1), SuffixSort();
    for(int i = 1; i <= n; i++)
        ans += n - sa[i] - ht[i];
    printf("%lld\n", ans + n);
    return 0;
}
