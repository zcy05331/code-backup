#include <bits/stdc++.h>
const int MaxN = 1000010;
int a[MaxN], cnt[10100];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        int l = 0,r = 0, pre = 0;
        double ans = 1e9, res = 0;
        for(register int i = 1; i <= n; i++)scanf("%d", &a[i]), cnt[a[i]]++;
        std::sort(a + 1, a + n + 1);
        for(register int i = 1; i <= n; i++)
        {
            if(cnt[a[i]] > 3)
            {
                l = r = a[i];
                break;
            }
            while(i < n && a[i] == a[i + 1])i++;
            if(cnt[a[i]] < 2)continue;
            if(!pre)
            {
                pre = a[i];
                continue;
            }
            res = ((double)(2 * (pre + a[i]))) * ((double)(2 * (pre + a[i]))) / (1ll * pre * a[i]);
            if(res < ans)ans = res, l = a[i], r = pre;
            pre = a[i];
        }
        printf("%d %d %d %d\n", l, l, r, r);
    }
    return 0;
}