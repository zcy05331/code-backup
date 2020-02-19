#include <bits/stdc++.h>
# define ll long long

const int MaxN = 100010;

struct node
{
    int w, val, pos, id, cnt;
};

struct BIT
{
    int n, c[MaxN];
    # define lowbit(x) (x & (-x))
    inline void add(int pos, int val)
    {
        while(pos <= n)
        {
            c[pos] += val;
            pos += lowbit(pos);
        }
    }
    inline int query(int pos)
    {
        int ans = 0;
        while(pos)
        {
            ans += c[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }
}T;

ll ans[MaxN];
int n, m, cnt;
node x[MaxN << 1];
int pos[MaxN], a[MaxN];

inline bool cmp(node a, node b)
{
    return a.pos < b.pos;
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

inline void cdq(int l, int r)
{
    if(l == r)
        return;
    int mid = (l + r) >> 1, j = l;
    cdq(l, mid), cdq(mid + 1, r);
    std::sort(x + l, x + mid + 1, cmp);
    std::sort(x + mid + 1, x + r + 1, cmp);
    for(int i = mid + 1; i <= r; i++)
    {
        while(j <= mid && x[j].pos <= x[i].pos)
            T.add(x[j].val, x[j].w), ++j;
        ans[x[i].id] += x[i].w * (T.query(n) - T.query(x[i].val));
    }
    for(int i = l; i < j; i++)
        T.add(x[i].val, -x[i].w);
    j = mid;
    for(int i = r; i > mid; --i)
    {
        while(j >= l && x[j].pos >= x[i].pos)
            T.add(x[j].val, x[j].w), --j;
        ans[x[i].id] += x[i].w * T.query(x[i].val - 1);
    }
    for(int i = mid; i > j; --i)
        T.add(x[i].val, -x[i].w);
}

int main()
{   
    int tmp = 0;
    n = read(), m = read(), T.n = n;
    for(int i = 1; i <= n; i++)
        a[i] = read(), pos[a[i]] = i, x[++cnt] = (node){1, a[i], i, 0, cnt};
    for(int i = 1; i <= m; i++)
        tmp = read(), x[++cnt] = (node){-1, tmp, pos[tmp], i, cnt};
    cdq(1, cnt);
    for(int i = 1; i <= m; i++)
        ans[i] += ans[i - 1];
    for(int i = 0; i < m; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
