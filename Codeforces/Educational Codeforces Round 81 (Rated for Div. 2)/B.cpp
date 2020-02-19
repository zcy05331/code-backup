#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

char s[MaxN];
int n, x, sum, ans, pre[MaxN][2], cnt[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%s", &n, &x, s + 1);
        for (int i = 1; i <= n; i++)
        {
            pre[i][0] = pre[i][1] = cnt[i] = 0;
            pre[i][0] = pre[i - 1][0], pre[i][1] = pre[i - 1][1];
            ((s[i] == '1') ? (pre[i][1]++) : (pre[i][0]++)), cnt[i] = pre[i][0] - pre[i][1];
        }
        ans = 0, sum = pre[n][0] - pre[n][1];
        if (sum == 0)
        {
            int flag = 1;
            if (x == 0)
                ++ans;
            for (int i = 1; i <= n; i++)
                if (cnt[i] == x)
                {
                    printf("-1\n"), flag = 0;
                    break;
                }
            if (flag)
                printf("0\n");
        }
        else
        {
            if (x == 0)
                ++ans;
            for (int i = 1; i <= n; i++)
            {
                if ((x - cnt[i]) * 1ll * sum < 0)
                    continue;
                if ((x - cnt[i]) % sum == 0 )
                    ++ans;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
