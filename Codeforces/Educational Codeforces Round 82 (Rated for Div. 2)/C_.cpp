#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

struct edge
{
    int next, to;
};

int n, cnt[MaxN], g[MaxN][MaxN];
char s[MaxN], ans[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int flag = 0;
        scanf("%s", s + 1), n = strlen(s + 1);
        for (int i = 1; i < n; i++)
            g[s[i] - 'a'][s[i + 1] - 'a'] = g[s[i + 1] - 'a'][s[i] - 'a'] = 1;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
                if (g[i][j])
                    cnt[i]++;
            if (cnt[i] >= 3)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            printf("NO\n");
            continue;
        }
        int pos = 0, num = 0;
        for (int i = 0; i < 26; i++)
        {
            if (!cnt[i])
                putchar(i + 'a'), ++num;
        }
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == 1)
                pos = i;
        }
        for (int i = 1; i <= 26 - num; i++)
        {
            for(int j = 0; j
        }
    }
    return 0;
}
