#include <bits/stdc++.h>

const int MaxN = 100010;
int ans[MaxN];
int a[MaxN], b[MaxN];

struct node
{
    int x, y;
    int last;
    bool operator < (node s)const
    {
        return a[x] + b[y] > a[s.x] + b[s.y];
    }
};

std::priority_queue<node> pq;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    std::sort(a + 1, a + n + 1);
    for(int j = 1; j <= n; j++)
        scanf("%d", &b[j]);
    std::sort(b + 1,b + n);
    pq.push((node){1, 1, false});
    for(int i = 1; i <= n; i++)
    {
        int x = pq.top().x, y = pq.top().y, flag = pq.top().last;
        ans[i] = a[x] + b[y];
        pq.pop();
        pq.push((node){x, y + 1, true});
        if(flag == 0)
            pq.push((node){x + 1, y, false});
    }
    std::sort(ans + 1, ans + n);
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}