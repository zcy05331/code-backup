#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct node
{
    int st, ed;
};

struct station
{
    int off, last, tim;
};

node a[MaxN];
station b[MaxN];
int n, m, k, dis[MaxN];

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
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i < n; i++)
        scanf("%d", &dis[i]);
    int t = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a[i].st, &t, &a[i].ed);
        b[t].last = std::max(b[t].last, a[i].st), b[a[i].ed].off++;
    }
    int time = 0;
    for (int i = 1; i <= n; i++)
    {
        b[i].tim = time;
        time = std::max(time, b[i].last), time += dis[i];
    }
    int maxnum = 0, maxpos = 0, tmp = 0;
    while (k--)
    {
        maxnum = 0;
        for (int i = 2; i <= n; i++)
        {
            if (!dis[i - 1])
                continue;
            tmp = 0;
            for (int j = i; j <= n; j++)
            {
                tmp += b[j].off;
                if (b[j].tim <= b[j].last)
                    break;
            }
            if (tmp > maxnum)
            {
                maxnum = tmp;
                maxpos = i;
            }
        }
        dis[maxpos - 1]--;
        for (int i = maxpos; i <= n; i++)
        {
            --b[i].tim;
            if (b[i].tim < b[i].last)
                break;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans += b[a[i].ed].tim - a[i].st;
    printf("%d\n", ans);
    return 0;
}
