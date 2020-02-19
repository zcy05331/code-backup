# include <bits/stdc++.h>
const int MaxN = 100010;
struct heap
{
    int ch[MaxN][2], val[MaxN], dis[MaxN], f[MaxN];
    int merge(int x, int y)
    {
        if(x == 0 || y == 0)
            return x + y;
        if(val[x] > val[y] || (val[x] == val[y] && x > y))
            std::swap(x, y);
        ch[x][1] = merge(ch[x][1], y);
        f[ch[x][1]] = x;
        if(dis[ch[x][0]] < dis[ch[x][1]])
            std::swap(ch[x][0], ch[x][1]);
        dis[x] = dis[ch[x][1]] + 1;
        return x;
    }
    int getf(int x)
    {
        while(f[x])
            x = f[x];
        return x;
    }
    void pop(int x)
    {
        val[x] = -1;
        f[ch[x][0]] = f[ch[x][1]] = 0;
        merge(ch[x][0], ch[x][1]);
    }
}T;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &T.val[i]);
    for(int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        if(op == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if(T.val[x] == -1 || T.val[y] == -1)
                continue;
            if(x == y)
                continue;;
            int fx = T.getf(x), fy = T.getf(y);
            T.merge(fx, fy);  
        }
        else
        {
            int x;
            scanf("%d", &x);
            if(T.val[x] == -1)
                puts("-1");
            else
            {
                int fx = T.getf(x);
                printf("%d\n", T.val[fx]);
                T.pop(fx);
            }
            
        }
    }
    return 0;
}