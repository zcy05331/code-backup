#include <bits/stdc++.h>

const int MaxN = 300010;

int n;
int w1[MaxN], w2[MaxN], fa[MaxN], ans[MaxN];

inline int getf(int x)
{
    if(x != fa[x])
        fa[x] = getf(fa[x]);
    return fa[x];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i, w1[i] = w2[i] = i;
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        int fu = getf(u), fv = getf(v);
        if(fu == fv)
            continue;
        fa[fu] = w1[fv], w2[fu] = w1[fv], w1[fv] = w1[fu];
    }
    int top = getf(1);
    int tmp, num = 0;
    tmp = w1[top];
    while(1)
    {
        ans[++num] = tmp;
        if(w2[tmp] == tmp)
            break;
        tmp = w2[tmp];
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
