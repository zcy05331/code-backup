#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    int x, y, dis;
};

struct cmp
{
    bool operator()(const node &a, const node &b)
    {
        return a.dis < b.dis;
    }
};

int f[1000010];
std::priority_queue<node, std::vector<node>, cmp> q;

int getf(int x)
{
    if (f[x] != x)
        return f[x] = getf(f[x]);
    return f[x];
}

int main()
{
    //freopen("testdata.in","r",stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2 * n; i++)
        f[i] = i;
    while (m--)
    {
        int x, y, dis;
        scanf("%d%d%d", &x, &y, &dis);
        q.push((node){x, y, dis});
    }
    while (q.size())
    {
        if (getf(q.top().x) == getf(q.top().y))
        {
            printf("%d\n", q.top().dis);
            return 0;
        }
        f[f[q.top().x]] = f[getf(q.top().y + n)];
        f[f[q.top().y]] = f[getf(q.top().x + n)];
        q.pop();
    }
    printf("0\n");
    return 0;
}