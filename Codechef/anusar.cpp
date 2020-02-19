#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

ll ans[MaxN];
char s[MaxN];
std::vector<int> st, vec[MaxN];
int n, m, q, h[MaxN], sa[MaxN], rk[MaxN];
int old[MaxN], buc[MaxN], l[MaxN], r[MaxN];

int comp(int x, int y) { return h[x] > h[y]; }
int cmp(int x, int y, int w) { return (old[x] == old[y] && old[x + w] == old[y + w]); }

void init()
{
    for (int i = 0; i < n + 10; i++)
        vec[i].clear(), ans[i] = 0;
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
            k--;
        while (s[i + k] == s[sa[rk[i] - 1] + k])
            ++k;
        h[rk[i]] = k;
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

void solve()
{
    st.push_back(0), h[0] = h[n + 1] = -1;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && h[i] <= h[st.back()])
            st.pop_back();
        l[i] = st.back() + 1, st.push_back(i);
    }
    st.clear(), st.push_back(n + 1);
    for (int i = n; i; i--)
    {
        while (!st.empty() && h[i] <= h[st.back()])
            st.pop_back();
        r[i] = st.back() - 1, st.push_back(i);
    }
    for (int i = 1; i <= n; i++)
        vec[h[i]].push_back(i);
    for (int i = n; i; i--)
    {
        int rt = 0;
        for (int j = 0; j < vec[i].size(); j++)
        {
            int pos = vec[i][j];
            ll len = r[pos] - l[pos] + 2, val = std::min(i, std::min(i - h[l[pos] - 1], i - h[r[pos] + 1]));
            if (r[pos] < rt)
                continue;
            ans[len] += len * val, rt = r[pos];
        }
    }
    for (int i = n - 1; i; i--)
        ans[i] += ans[i + 1];
    ans[1] = n * 1ll * (n + 1) / 2;
}

int main()
{
    int T = read();
    while (T--)
    {
        init();
        scanf("%s", s + 1), n = strlen(s + 1);
        SuffixSort(), solve(), q = read();
        while (q--)
        {
            int x = read();
            printf("%lld\n", ans[(x > n) ? 0 : x]);
        }
    }
    return 0;
}
