#include <bits/stdc++.h>
#define getblock(x) ((x - 1) / size + 1)
#define getl(x) ((x - 1) * size)
#define getr(x) std::min(n, getl(x + 1) - 1)
#define check()                 \
    for (int i = 0; i < n; i++) \
        printf("%d %d\n", t[i], next[i]);
const int MaxN = 200010;
int a[MaxN];
int t[MaxN], next[MaxN];
int size;
int n, m;

void update(int l, int r)
{
    for(int i = r; i >= l; i--)
    {
        if(i + a[i] > getr(getblock(i + 1)))t[i] = 1, next[i] = i + a[i];
        else t[i] = t[i + a[i]] + 1, next[i] = next[i + a[i]];
    }
}
int main()
{

    scanf("%d", &n);
    size = int(sqrt(n));
    if (size * size < n)
        size++;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int cur = i;
        while (cur < n && cur <= getr(getblock(i + 1)))
        {
            cur += a[cur];
            t[i]++;
        }
        next[i] = cur;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int op, cur;
        scanf("%d%d", &op, &cur);
        if (op == 1)
        {
            long long ans = 0;
            while (cur < n)
            {
                ans += t[cur];
                cur = next[cur];
            }
            printf("%lld\n", ans);
        }
        else
        {
            int delta;
            scanf("%d", &delta);
            a[cur] = delta;
            update(getl(getblock(cur)), cur);
            
        }
    }
    return 0;
}