#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

char s[MaxN];
int n, now, a[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%s", &n, s + 1), s[n] = '>', now = n;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '>')
            {
                printf("%d ", now--);
                continue;
            }
            int cnt = 0;
            while (i + cnt <= n && s[i + cnt] == '<')
                ++cnt;
            for (int j = now - cnt; j <= now; j++)
                printf("%d ", j);
            now -= (cnt + 1), i += cnt;
        }
        puts("");
        now = 1, s[n] = '<';
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '<')
            {
                printf("%d ", now++);
                continue;
            }
            int cnt = 0;
            while (i + cnt <= n && s[i + cnt] == '>')
                ++cnt;
            for (int j = now + cnt; j >= now; j--)
                printf("%d ", j);
            now += (cnt + 1), i += cnt;
        }
        puts("");
    }
    return 0;
}
