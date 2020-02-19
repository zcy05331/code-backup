#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const int MaxN = 500010;
long long n, d, k, x[MaxN] = {}, s[MaxN] = {}, dp[MaxN] = {};
long long l, r;
int check(long long c)
{
    int pmin = 0, pmax = 0;
    pmin = std::max(d - c, 1ll);
    pmax = d + c;
    std::deque<int> q;
    dp[0] = 0;
    int head = 0;
    for (int i = 1; i <= n; i++)
    {
        while(x[i] >= pmin + x[head])
        {
            while(!q.empty() && dp[head] >= dp[q.back()])
                q.pop_back();
            q.push_back(head);
            head++;
        }
        while(!q.empty() && x[i] > pmax + x[q.front()])
            q.pop_front();
        if(q.empty())
            dp[i] = -0x3f3f3f3f3f;
        else 
            dp[i] = dp[q.front()] + s[i];
        if(dp[i] >= k)return 1;
    }
    return 0;
}
int main()
{
    long long sum = 0;
    scanf("%lld%lld%lld", &n, &d, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &x[i], &s[i]);
        if (s[i] > 0)
            sum += s[i];
    }
    if (sum < k)
    {
        printf("-1");
        return 0;
    }
    l = 0;
    r = x[n] + 1;
    long long ans = -1;
    while (l <= r)
    {   
        long long mid = (l + r) >> 1;
        if (check(mid))
            ans = mid,r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%lld", ans);
    return 0;
}