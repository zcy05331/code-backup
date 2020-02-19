#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e6 + 10;

char s[MaxN];
std::vector<ll> st;
ll n, m, ans, l[MaxN], r[MaxN], h[MaxN];
ll sa[MaxN], rk[MaxN], old[MaxN], buc[MaxN];

int cmp(int x, int y, int w){ return (old[x] == old[y]) && (old[x + w] == old[y + w]); }

void Sort()
{
    for(int i = 0; i <= m; i++) buc[i] = 0;
    for(int i = 1; i <= n; i++) buc[rk[i]]++;
    for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
    for(int i = n; i; i--) sa[buc[rk[old[i]]]--] = old[i];
}

void SuffixSort()
{
    m = 300;
    for(int i = 1; i <= n; i++)
        rk[i] = s[i], old[i] = i;
    Sort();
    for(int w = 1, p = 0; p < n; m = p, w <<= 1)
    {
        p = 0;
        for(int i = 1; i <= w; i++)
            old[++p] = n - w + i;
        for(int i = 1; i <= n; i++)
            if(sa[i] > w)
                old[++p] = sa[i] - w;
        Sort(), std::swap(rk, old), rk[sa[1]] = p = 1;
        for(int i = 2; i <= n; i++)
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    }
    ll k = 0;
    for(int i = 1; i <= n; i++)
    {
        if(k) --k;
        while(s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
        h[rk[i]] = k;
    }
}

int main()
{   
    scanf("%s", s + 1), n = strlen(s + 1);
    ans = n * (n - 1) * (n + 1) / 2, SuffixSort();
    h[0] = h[n + 1] = -1, st.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        while(!st.empty() && h[st.back()] > h[i])
            st.pop_back();
        l[i] = st.back(), st.push_back(i);
    }
    st.clear(), st.push_back(n + 1);
    for (int i = n; i; i--)
    {
        while (!st.empty() && h[st.back()] >= h[i])
            st.pop_back();
        r[i] = st.back(), st.push_back(i);
    }
    for(int i = 1; i <= n; i++)
        ans -= 2ll * (i - l[i]) * (r[i] - i) * h[i];
    printf("%lld\n", ans);
    return 0;
}
