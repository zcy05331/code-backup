#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN << 5];
std::vector<int> vec;
int n, cnt, tot, a[MaxN], pri[MaxN], head[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void p(int n)
{
    pri[0] = pri[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!pri[i])
        {
            ++tot;
            a[i] = tot;
            for (int j = 2 * i; j <= n; j += i)
            {
                pri[j] = 1;
                if (!a[j])
                    a[j] = tot;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    p(n);
    for (int i = 2; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}
