#include<bits/stdc++.h>

int n,m;
int a[100010], b[100010];
std::map<long long, int>p;

int pd(long long x)
{
    for (int i = 2, to = sqrt(x); i <= to; i++)
        if (x % i == 0)
            return 2;
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        p.clear();
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d",&a[i]);
            if (a[i] != 1)
                p[a[i]]++;
        }
        for(int i = 1; i<= m; ++i)
        {
            scanf("%d", &b[i]);
            if(b[i] != 1)
                p[b[i]]--;
        }
        int num = 0;
        long long s = 1;
        for(std::map<long long, int>::iterator it = p.begin(); it != p.end(); it++)
        {
            std::pair<long long, int> x = *it;
            if(x.second <= 0)continue;
            if(x.second >= 2)num = 2;
            num += pd(x.first);
            if(num > 1)break;
        }
        if(num == 1)puts("YES");
        else printf("NO\n");
    }
    return 0;
}