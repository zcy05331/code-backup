#include <bits/stdc++.h>
const int MaxN = 30010;
int f[MaxN], front[MaxN], num[MaxN];
int find(int x)
{
    if(f[x] == x)return x;
    int fx = find(f[x]);
    front[x] += front[f[x]];
    f[x] = fx;
    return fx;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= MaxN; i++)f[i] = i, front[i] = 0, num[i] = 1;
    while (T--)
    {
        char op;
        int x, y;
        std::cin >> op;
        scanf("%d%d", &x, &y);
        if (op == 'M')
        {
            int fx = find(x), fy = find(y);
            f[fx] = fy;
            front[fx] += num[fy];
            num[fy] += num[fx];
            num[fx] = 0;
        }
        else if (op == 'C')
        {
            if(find(x) != find(y))printf("-1\n");
            else printf("%d\n", abs(front[y] - front[x]) - 1);
            
        }
    }
    return 0;
}