#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 110;
const int base = 331;

struct edge
{
    int next, to;
};

edge e[MaxN];
int n, m, cnt;
int head[MaxN], ans[MaxN][MaxN];

void init() { cnt = 0, memset(head, 0, sizeof(head)); }

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

ll Hash(int u, int fa)
{
    std::vector<ll> q;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        q.push_back(Hash(v, u));
    }
    ll ans = 0;
    std::sort(q.begin(), q.end());
    for (int i = 0; i < q.size(); i++)
        ans = ans * base + q[i];
    return ans * base + MaxN + 1;
}

int main()
{
    m = read();
    for (int i = 1; i <= m; i++)
    {
        init(), n = read();
        for (int j = 1; j <= n; j++)
        {
            int f = read();
            if (f)
                add_edge(j, f), add_edge(f, j);
        }
        for (int j = 1; j <= n; j++)
            ans[i][j] = Hash(j, 0);
        std::sort(ans[i] + 1, ans[i] + n + 1);
        for (int j = 1; j <= i; j++)
        {
            int k = 0;
            while (k <= n)
                if ((++k) && (ans[i][k] != ans[j][k]))
                    break;
            if (k > n)
            {
                printf("%d\n", j);
                break;
            }
        }
    }
    return 0;
}
