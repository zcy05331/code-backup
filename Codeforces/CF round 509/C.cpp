#include <bits/stdc++.h>

const int MaxN = 200010;

struct coffee
{
    int id;
    int t;
};

coffee a[MaxN];
int ans[MaxN];

int cmp1(coffee a, coffee b){return a.t < b.t;}

int cmp2(coffee a, coffee b){return a.id < b.id;}

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;

int main()
{
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].t);
        a[i].id = i;
    }
    std::sort(a + 1, a + n + 1, cmp1);
    ans[a[1].id] = 1;
    std::pair<int, int> t;
    t = std::make_pair(a[1].t, 1);
    int cnt = 1;
    pq.push(t);
    for(int i = 2; i <= n; i++)
    {    
        t = pq.top();
        if(a[i].t - t.first > d)
            pq.pop();
        else t.second = ++cnt;
        t.first = a[i].t;
        ans[a[i].id] = t.second;
        pq.push(t);
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}