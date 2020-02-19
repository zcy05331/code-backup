#include <bits/stdc++.h>
const int Max = 1010;
int tmp[Max];
struct edge
{
    int to, next;
}e[Max * Max];
int head[Max];
int vis[Max];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        memset(vis, 0, sizeof(vis));
        int s;
        scanf("%d", &s);
        for(int j = 1; j <= s; j++)
        {
            scanf("%d", &tmp[j]);
            
        }
        for(int j = 1; j <= s; j++)
        {
            for(int k = 1; k <= tmp[j]; k++)
            {

            }
        }
    }
    return 0;
}