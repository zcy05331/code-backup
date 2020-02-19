#include <bits/stdc++.h>

const int MaxN = 100010;
int a[MaxN];
int n;

int check(int x)
{
    int now = 1,minx = n,last = 1;
    while(now <= n)
    {
        if(a[now] + 1 != a[now + 1])minx = std::min(minx, now - last + 1);
        now++;
    }
    return minx >= x;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    std::sort(a + 1, a + n + 1);
    int l = 1, r = n + 1;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(check(mid))l = mid;
        else r = mid - 1;
    }
    printf("%d", l);
    return 0;
}