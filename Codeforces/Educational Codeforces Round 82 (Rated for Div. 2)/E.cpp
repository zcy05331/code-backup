#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int n, m;
std::string s, t;
const int MaxN = 4e2 + 10;
int dp[MaxN][MaxN], next[MaxN][27];

int chk(int len)
{
    for (int i = 0; i <= len - 1; i++)
    {
        for (int j = len - 1; j <= m; j++)
        {
            if (!i && j == len - 1)
            {
                dp[i][j] = 0;
                continue;
            }
            else
            {
                if (!i)
                {
                    dp[i][j] = next[dp[i][j - 1]][t[j] - 'a' + 1];
                    continue;
                }
                if (j == len - 1)
                {
                    dp[i][j] = next[dp[i - 1][j]][t[i] - 'a' + 1];
                    continue;
                }
                dp[i][j] = std::min(next[dp[i - 1][j]][t[i] - 'a' + 1], next[dp[i][j - 1]][t[j] - 'a' + 1]);
            }
        }
    }
    return (dp[len - 1][m] <= n);
}

signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        std::cin >> s >> t;
        n = s.length(), m = t.length(), s = " " + s;
        memset(next, 0, sizeof(next));
        for (int i = 1; i <= 26; i++)
        {
            next[n][i] = n + 1;
            next[n + 1][i] = n + 1;
        }
        for (int i = n - 1; ~i; i--)
        {
            for (int j = 1; j <= 26; j++)
                next[i][j] = next[i + 1][j];
            next[i][s[i + 1] - 'a' + 1] = i + 1;
        }
        t = " " + t;
        int flag = 0;
        for (int i = 1; i <= m; i++)
            flag |= chk(i);
        printf(flag ? "Yes" : "No");
    }
    return 0;
}