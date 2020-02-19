#include <bits/stdc++.h>

int n,m;
int a[1010];
int l, r;
std::queue<int> q;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &l, &r);
        for(int i = l; i <= r; i++)
        {
            ++a[i];
        }
    }
    int ans = 0;
    for(int i = 1;i <= m; i++)
    {
        if (!a[i])
        {
            q.push(i);
            ans++;
        }
    }
    printf("%d\n", ans);
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
    return 0;
}