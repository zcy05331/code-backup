#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

ll ans = 0;
int n, m, k, d, cnt, a[MaxN], c[MaxN];

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

int main()
{
    int T = read();
    while (T--)
    {
        cnt = 0, ans = 0;
        n = read(), m = read(), k = read(), d = read();
        for (int i = 1; i <= m; i++)
            c[i] = read();
        for (int i = 1; i <= k; i++)
            a[i] = read();
        std::sort(a + 1, a + k + 1);
        std::sort(c + 1, c + m + 1);
        a[0] = 1, a[k + 1] = n;
        for (int i = 0; i <= k; i++)
            if (a[i + 1] - a[i] > d) ++cnt;
        if (cnt)
        {
            ans = cnt * 1ll * c[1];
            for (int i = 2; i <= m; i++)
                ans += c[i];
        }
        else
        {
            cnt = m;
            for(int i = 0, j = 0; i <= k; i++)
            {
                while(j <= k && a[j + 1] <= a[i] + d) ++j;
                if(j == k + 1) break;
                cnt = std::min(cnt, j - i);
            }
            // printf("cnt: %d\n", cnt);
            for(int i = 1; i <= m - cnt; i++)
                ans += c[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
