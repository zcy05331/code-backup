#include <bits/stdc++.h>

const int MaxN = 1600;

std::vector<int> son[MaxN];
int f[MaxN][2];

int dfs(int cur)
{
    for(int i = 0; i < son[cur].size(); i++)
    {
        int s = son[cur][i];
        dfs(s);
        f[cur][0] += f[s][1];;
        f[cur][1] += std::min(f[s][0], f[s][1]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        f[i][1] = 1;
    for(int i = 0; i < n; i++)
    {
        int num, cnt, tmp;
        scanf("%d%d", &num, &cnt);
        for(int j = 1; j <= cnt; j++)
            scanf("%d", &tmp), son[num].push_back(tmp);
    }
    dfs(0);
    printf("%d", std::min(f[0][0],f[0][1]));
    return 0;
}