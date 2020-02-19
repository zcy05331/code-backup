#include <bits/stdc++.h>

const int MaxN = 500010;
int a[MaxN];
int en;
int n;
int work(int start)
{
    for(int i = start + 1; i <= n; i++)
        if(2 * a[i] <= a[i + 1])
        {
            en = i;
            return en - start + 1;
        }
}
int main()
{
    int ans = 1;
    int st = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[n + 1] = 0x7f7f7f7f;
    for(int i = 1; i < n; i++)
        if(a[i + 1] < 2 * a[i])
        {
            st = i;
            ans = std::max(work(st), ans);
            i = en;
        }   
    printf("%d", ans);
    return 0;
}
