#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct node
{
    int val;
    int num[8];
};

node t[MaxN];
int n, p, k;
ll sum[MaxN], f[MaxN][260];

int cmp(node a, node b) { return a.val > b.val; }
int check(int cnt, int x) { return cnt <= x - 1 && k + cnt >= x; }

void init()
{
    std::sort(t + 1, t + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + t[i].val;
}

int main()
{
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i].val);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
            scanf("%d", &t[i].num[j - 1]);
    }
    init();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (1 << p); j++)
        {
            int cnt = 0, tmp = j;
            while (tmp)
                ++cnt, tmp ^= tmp & -tmp;
            if (cnt > i) continue;
            if (check(cnt, i))
                f[i][j] = f[i - 1][j] + t[i].val;
            else
                f[i][j] = f[i - 1][j];
            for (int x = 0; x < p; x++)
                if (j & (1 << x))
                {
                    int left = j ^ (1 << x);
                    f[i][j] = std::max(f[i][j], f[i - 1][left] + t[i].num[x]);
                }
        }
    }
    printf("%lld\n", f[n][(1 << p) - 1]);
    return 0;
}
