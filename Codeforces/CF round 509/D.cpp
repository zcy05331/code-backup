#include <bits/stdc++.h>

const int MaxN = 200010;

int n, h;
std::pair<int, int> p[MaxN];
int last[MaxN];
int s[MaxN];
int f[MaxN][50];

int main()
{
    
    scanf("%d%d", &n, &h);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &p[i].first, &p[i].second);
    for(int i = 1; i < n; i++)
        f[i][0] = p[i + 1].first - p[i].second;
    for(int t = 1; (1 << t) <= n; t++)
    {
        for(int i = 1; i + (1 << t) <= n; i++)
            f[i][t] = f[i][t - 1] + f[i + (1 << (t - 1))][t - 1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int left = h, pos = i;
        for(int j = 21; ~j; j--)
        {
            if(pos + (1 << j) <= n && f[pos][j] < left)
                left -= f[pos][j], pos += 1 << j;
        }
        ans = std::max(ans, p[pos].second - p[i].first + left);
    }
    printf("%d\n", ans);
    return 0;
}