// luogu-judger-enable-o2
#include <bits/stdc++.h>

#define ll long long

#define add(a, b) a = ((a % mod + b % mod) % mod)

const int MaxN = 100001, MaxK = 101;

const int mod = 1e9 + 7;

int n, k;

int size[MaxN];

int g[MaxK][2][2];

int f[MaxN][MaxK][2][2];


std::vector<int> edge[MaxN];

void dfs(int u, int fa)
{
    size[u] = 1;
    f[u][0][0][0] = f[u][1][1][0] = 1;
    for (auto v : edge[u])
    {
        if (v != fa)
        {
            dfs(v, u);
            for (int i = 0, l = std::min(size[u], k); i <= l; i++)
            {
                g[i][0][0] = f[u][i][0][0], f[u][i][0][0] = 0;
                g[i][0][1] = f[u][i][0][1], f[u][i][0][1] = 0;
                g[i][1][0] = f[u][i][1][0], f[u][i][1][0] = 0;
                g[i][1][1] = f[u][i][1][1], f[u][i][1][1] = 0;
            }
            for (int i = 0, l = std::min(size[u], k); i <= l; i++)
            {
                for (int j = 0, l2 = std::min(size[v], k - i); j <= l2; j++)
                {
                    add(f[u][i + j][0][0], (ll)g[i][0][0] * (ll)f[v][j][0][1]);
                    add(f[u][i + j][0][1], (ll)g[i][0][1] * (ll)(f[v][j][0][1] + f[v][j][1][1]) + (ll)g[i][0][0] * (ll)f[v][j][1][1]);
                    add(f[u][i + j][1][0], (ll)g[i][1][0] * (ll)(f[v][j][0][0] + f[v][j][0][1]));
                    add(f[u][i + j][1][1], (ll)g[i][1][0] * (ll)(f[v][j][1][0] + f[v][j][1][1]) + (ll)g[i][1][1] * ((ll)f[v][j][0][0] + (ll)f[v][j][0][1] + (ll)f[v][j][1][0] + (ll)f[v][j][1][1]));
                }
            }
            size[u] += size[v];
        }
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d", ((f[1][k][0][1] + f[1][k][1][1]) % mod + mod) % mod);
    return 0;
}