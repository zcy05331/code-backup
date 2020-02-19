#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

struct node
{
    ll val, x, y;
};

std::vector<int> vec1;
std::vector<node> vec;
ll n, x[MaxN], y[MaxN], f[MaxN], g[MaxN][MaxN];

int cmp(node x, node y) { return x.val < y.val; }

ll getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

inline void merge(int x, int y)
{
    int fx = getf(x), fy = getf(y);
    if (fx > fy)
        std::swap(fx, fy);
    f[fy] = fx;
}

ll dis(int a, int b) { return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]); }

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        x[i] = read(), y[i] = read(), f[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            g[i][j] = g[j][i] = dis(i, j), vec.push_back((node){g[i][j], i, j});
    int m = vec.size();
    std::sort(vec.begin(), vec.end(), cmp);
    vec.push_back((node){-1ll, 0ll, 0ll});
    int now = 0;
    for (int i = 0; i < m; i++)
    {
        printf("%lld %lld %lld\n", vec[i].val, vec[i].x, vec[i].y);
        if ((vec[i].val != vec[i + 1].val) && (i - now + 1) > 1)
        {
            vec1.clear();
            for (int j = now; j <= i; j++)
                vec1.push_back(vec[j].x), vec1.push_back(vec[j].y);
            std::sort(vec1.begin(), vec1.end()), vec1.push_back(-1);
            for (int j = 0; j < vec1.size() - 1; j++)
                if ((vec1[j] != vec1[j + 1]) && (vec1[j + 1] > 0))
                    merge(vec1[j], vec1[j + 1]);
            now = i + 1;
        }
        else if (vec[i].val != vec[i + 1].val)
            now = i + 1;
    }
    vec1.clear();
    for (int i = 1; i <= n; i++)
        if (getf(i) == 1)
            vec1.push_back(i);
    printf("%d\n", vec1.size());
    for (int i = 0; i < vec1.size(); i++)
        printf("%d ", vec1[i]);
    return 0;
}
