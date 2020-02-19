#include <bits/stdc++.h>

int main()
{
    int n, tmp;
    long long cnt = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        if(tmp)++cnt;
        else ans += cnt;
    }
    printf("%I64d", ans);
    return 0;
}