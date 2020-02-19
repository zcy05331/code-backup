#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10;

int n, m, maxy, miny = 0x3f3f3f3f;
std::vector<std::pair<int, int>> vec;

struct node
{
    int l, r;
    int max, min, tag;
};

struct SegmentTree
{
    node t[MaxN << 2];
    int build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
        {
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
    }
};

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

int main()
{
    int y, r;
    scanf("%d", &n);
    for (int i = 1; i = n; i++)
    {
        y = read(), r = read();
        vec.push_back(std::make_pair(y, r));
        maxy = std::max(y, maxy), miny = std::min(y, miny);
    }
    for(int i = 1; i <= n; i++)
    return 0;
}
