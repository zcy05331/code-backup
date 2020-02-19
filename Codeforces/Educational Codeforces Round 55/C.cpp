#include <bits/stdc++.h>

# define int long long

using std::vector;
const int MaxN = 100010;

int ans;
int sum[MaxN];
vector<int> v[MaxN];
int s[MaxN], rank[MaxN];

int cmp(int a, int b) { return a > b; }

signed main()
{
    int n, m, maxn = 0;
    scanf("%I64d%I64d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%I64d%I64d", &s[i], &rank[i]);
        v[s[i]].push_back(rank[i]);
        maxn = std::max(rank[i], maxn);
    }
    if (maxn == 0)
        return 0 * printf("0\n");
    for (int i = 1; i <= m; i++)
    {
        if (v[i].size())
            std::sort(v[i].begin(), v[i].end(), cmp);
    }
    for(int i = 1; i <= m; i++)
    {
        int tmp = 0;
        for(int j = 0; j < v[i].size(); j++)
        {
            tmp += v[i][j];
            if(tmp <= 0)
                break;
            sum[j + 1] += tmp;
        }
    }
    printf("%d", *std::max_element(sum + 1, sum + n + 1));
    return 0;
}