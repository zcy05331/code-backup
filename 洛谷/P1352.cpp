#include <bits/stdc++.h>
const int MaxN = 10010;
std::vector<int> son[MaxN];
int f[MaxN][2], v[MaxN], h[MaxN], n;
void dp(int x)
{
    f[x][0] = 0;
    f[x][1] = h[x];
    for(int i = 0; i < son[x].size(); i++)
    {
        int y = son[x][i];
        dp(y);
        f[x][0] += std::max(f[y][0], f[y][1]);
        f[x][1] += f[y][0];
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)scanf("%d", &h[i]);
    for(int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x] = 1;
        son[y].push_back(x);
    }
    int root;
    for(int i = 1; i <= n; i++)
    {
        if(!v[i])
        {
            root = i;
            break;
        }
    }
    dp(root);
    printf("%d\n", std::max(f[root][0], f[root][1]));
    return 0;
}
