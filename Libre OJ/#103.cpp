#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

int n, m, nxt[MaxN];
char s[MaxN], t[MaxN];

signed main()
{
    int ans = 0;
    scanf("%s%s", t + 1, s + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && s[i] != s[j + 1])
            j = nxt[j];
        if (s[j + 1] == s[i]) ++j;
        nxt[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i++)
    {
        while(j && s[j + 1] != t[i])
            j = nxt[j];
        if(s[j + 1] == t[i]) ++j;
        if(j == n) ++ans, j = nxt[j];
    }
    printf("%d\n", ans);
    return 0;
}
