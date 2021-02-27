#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

char s[MaxN], t[MaxN];
int n, m, pl[MaxN], pr[MaxN], nxt[MaxN][26], nxt1[MaxN][26];

signed main()
{
    scanf("%d%d", &n, &m);
    scanf("%s%s", s + 1, t + 1);
    for (int i = 0; i < 26; i++)
        nxt[n][i] = n + 1;
    nxt[n][s[n] - 'a'] = n;
    for (int i = n - 1; ~i; i--)
    {
        for (int j = 0; j < 26; j++)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - 'a'] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
            nxt1[i][j] = nxt1[i - 1][j];
        nxt1[i][s[i] - 'a'] = i;
    }
    int l = 1, r = n, ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if(i > 1)
            ans = std::max(ans, nxt[l][t[i] - 'a'] - l);
        if(l == nxt[l][t[i] - 'a'] && i > 1) ++l;
        l = nxt[l][t[i] - 'a'], pl[i] = l;
    }
    for(int i = m; i; i--)
    {
        if(i < m)
            ans = std::max(ans, r - nxt1[r][t[i] - 'a']);
        if (r == nxt1[r][t[i] - 'a'] && i < m) --r;
        r = nxt1[r][t[i] - 'a'], pr[i] = r;
    }
    // for(int i = 1; i <= m; i++)
    //     printf("%d ", pl[i]);
    // for(int i = 1; i <= m; i++)
    //     printf("%d ", pr[i]);
    for(int i = 1; i < m; i++)
        ans = std::max(ans, pr[i + 1] - pl[i]);
    printf("%d\n", ans);
    return 0;
}
