#include <bits/stdc++.h>

const int MaxN = 100010, MaxT = 60;

int cnt[MaxT][MaxT][MaxN * 2 / 3];
int len, n, m, l, t, L, R, c, mod;
int appnum[MaxT][MaxT], mode[MaxT][MaxT];
int st[MaxT], ed[MaxT], vec[MaxN], vec2[MaxN], a[MaxN], val[MaxN], num[MaxN];

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

void unique()
{
    memcpy(vec, a, sizeof(a));
    std::sort(vec + 1, vec + n + 1);
    for (register unsigned i = 1; i <= n; ++i)
        if (i == 1 || vec[i] != vec[i - 1])
            val[++len] = vec[i];
    for (register unsigned i = 1; i <= n; ++i)
        num[i] = std::lower_bound(val + 1, val + len + 1, a[i]) - val;
}

void prework()
{
    t = (int)pow(n * 1.0, 1.0 / 3);
    if (t)
        l = n / t;
    for (register unsigned i = 1; i <= t; i++)
        st[i] = (i - 1) * l + 1, ed[i] = i * l;
    if (ed[t] < n)
        st[t + 1] = ed[t] + 1, ed[++t] = n;
    else if(ed[t] > n)
        ed[t] = n;
    for (register unsigned i = 1; i <= t; ++i)
    {
        for (register unsigned j = i; j <= t; ++j)
        {
            for (register unsigned k = st[i]; k <= ed[j]; ++k)
                cnt[i][j][num[k]]++;
            for (register unsigned k = 1; k <= len; ++k)
                if (cnt[i][j][k] > appnum[i][j] || (cnt[i][j][k] == appnum[i][j] && k < mode[i][j]))
                    appnum[i][j] = cnt[i][j][k], mode[i][j] = k;
        }
    }
}

inline void upd(int x)
{
    ++cnt[L][R][num[x]];
    if (cnt[L][R][num[x]] > c || (cnt[L][R][num[x]] == c && num[x] < mod))
        c = cnt[L][R][num[x]], mod = num[x];
}

inline int slove(int x, int y)
{
    register unsigned l = 0, r = 0;    

    for (register unsigned i = l; i <= t; ++i)
        if (x <= ed[i])
        {
            l = i;
            break;
        }
    
    for (register unsigned i = t; i; --i)
        if (y >= st[i])
        {
            r = i;
            break;
        }
    
    if (l + 1 <= r - 1)
        L = l + 1, R = r - 1;
    else
        L = R = 0;
    c = appnum[L][R], mod = mode[L][R];
    if (l == r)
    {
        for (register unsigned i = x; i <= y; ++i)
            upd(i);
        for (register unsigned i = x; i <= y; ++i)
            cnt[L][R][num[i]]--;
    }
    else
    {
        for (register unsigned i = x; i <= ed[l]; ++i)
            upd(i);
        for (register unsigned i = st[r]; i <= y; ++i)
            upd(i);
        for (register unsigned i = x; i <= ed[l]; ++i)
            --cnt[L][R][num[i]];
        for (register unsigned i = st[r]; i <= y; ++i)
            --cnt[L][R][num[i]];
    }
    return val[mod];
}

int main()
{
    // freopen("ex_1.in", "r", stdin);
    // freopen("ex_1(1).out", "w", stdout);
    int lastans = 0;
    n = m = read();
    for (register unsigned i = 1; i <= n; ++i)
        a[i] = read();
    unique();
    prework();
    for (register unsigned i = 1; i <= m; ++i)
    {
        int l0 = read(), r0 = read();
        printf("%d\n", slove(l0, r0));
    }
    return 0;
}