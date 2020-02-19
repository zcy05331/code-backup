#include <bits/stdc++.h>

struct node
{
    int p;
    int c;
};

node a[3010];
int x[3001];

int cmp(node a, node b)
{
    return a.c < b.c;
}

int main()
{
    int n, m;
    int cnt = 0;
    int vote = 0;
    int maxn = -1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int p, c;
        scanf("%d%d", &p, &c);
        x[p]++;
        if (p == 1)
            continue;  
        else
        {
            cnt++;
            a[cnt].c = c;
            a[cnt].p = p;
            maxn = std::max(p, maxn);
        }
    }
    if(x[1] > maxn)
    {
        printf("0");
        return 0;
    }
    std::sort(a + 1, a + cnt + 1, cmp);
    long long ans = 0;
    for(int i = 1; i <= cnt; i++)
    {
        
    }
    return 0;
}