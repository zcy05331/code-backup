# include <bits/stdc++.h>

const int MaxT = 4000110, MaxN = 501;

int n, m, t, tim[MaxN], cnt[MaxT], f[MaxT], sum[MaxT];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &tim[i]), t = std::max(tim[i], t), cnt[tim[i]]++, sum[tim[i]] += tim[i];
    for(int i = 1; i < t + m; i++)
        cnt[i] += cnt[i - 1], sum[i] += sum[i - 1];
    for(int i = 0; i < t + m; i++)
    {
        
        if(i >= m && cnt[i] == cnt[i - m])
        {
            f[i] = f[i - m];
            continue;
        } 
        f[i] = cnt[i] * i - sum[i];
        for(int j = std::max(i - 2 * m + 1, 0); j <= i - m; j++)
            f[i] = std::min(f[i], f[j] + (cnt[i] - cnt[j]) * i - (sum[i] - sum[j]));
    }
    int ans = 0x7f7f7f7f;
    for(int i = t; i < t + m; i++)
        ans = std::min(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}
