#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

char s[MaxN];
int n, t, pre[MaxN], next[MaxN], vis[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(pre, 0, sizeof(pre));
        memset(next, 0, sizeof(next));
        memset(vis, 0, sizeof(vis));
        int flag = 0;
        scanf("%s", s + 1), n = strlen(s + 1), vis[s[1]] = 1;
        for (int i = 2, pos = s[1]; i <= n; pos = s[i], vis[s[i]] = 1, i++)
        {
            if (s[i] == pre[pos] || s[i] == next[pos])
                continue;
            else if (vis[s[i]])
            {
                flag = 1;
                break;
            }
            else if (!pre[pos])
                pre[pos] = s[i], next[s[i]] = pos;
            else if (!next[pos])
                next[pos] = s[i], pre[s[i]] = pos;
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            puts("NO");
            continue;
        }
        else
        {
            puts("YES");
            for (int i = 'a'; i <= 'z'; i++)
                if (!vis[i])
                    putchar(i);
            int t;
            for (t = s[1]; pre[t];)
                t = pre[t];
            for (; t; t = next[t])
                putchar(t);
            puts("");
        }
    }
    return 0;
}
