#include <bits/stdc++.h>
const int MaxN = 310;
std::vector<int>son[MaxN];
int f[MaxN][MaxN];
int score[MaxN], v[MaxN];
int n, m;
void dp(int x)
{
    f[x][0] = 0;
    for(int i = 0; i < son[x].size(); i++)
    {
        int y = son[x][i];
        dp(y);
        for(int t = m; t >= 0; t--)
        {
            for(int j = t; j >= 0; j--)
                if(t - j >= 0)
                    f[x][t] = std::max(f[x][t], f[x][t - j] + f[y][j]);
        }
    }
    if(x != 0)
        for(int t = m; t > 0; t--)
            f[x][t] = f[x][t - 1] + score[x];
}
int main()
{
    int root = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        int k, s;
        scanf("%d%d", &k, &s);
        son[k].push_back(i);
        score[i] = s;
    }   
    dp(0);
    printf("%d\n", f[0][m]);
    return 0;
}