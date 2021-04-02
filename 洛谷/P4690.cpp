#include <bits/stdc++.h>

#define R register
#define pair std::pair<int, int>
#define mp(i, j) std::make_pair(i, j)
#define It std::set<node>::iterator
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 1e5 + 10;

struct query
{
    int tim, l, r, id;
} q[MaxN];

struct change
{
    int tim, pos, pre, v;
} c[MaxN * 10];

struct node
{
    int l, r, v;
    bool operator<(const node &x) const { return r < x.l; }
};

std::vector<int> vec;
std::set<pair> col[MaxN << 1];
int op[MaxN], l[MaxN], r[MaxN], val[MaxN], lst[MaxN << 1];
int n, m, len, cnt, cntq, cntc, a[MaxN], ans[MaxN], pre[MaxN];

struct ChthollyTree
{
    std::set<node> s;

    void update(int x, int now)
    {
        c[++cntc] = {++cnt, x, pre[x], -1};
        c[++cntc] = {++cnt, x, pre[x] = now, 1};
    }

    void init()
    {
        for (int i = 1; i <= n; i++)
        {
            c[++cntc] = {++cnt, i, lst[a[i]], 1};
            pre[i] = lst[a[i]], lst[a[i]] = i;
            s.insert((node){i, i, a[i]}), col[a[i]].insert(mp(i, i));
        }
        for (int i = 1; i <= len; i++)
            col[i].insert(mp(0, 0));
    }

    void insert(int l, int r, int v)
    {
        std::set<pair>::iterator it1 = col[v].upper_bound(mp(l, r)), it2 = it1;
        --it2;
        if (it1 != col[v].end()) update(it1->first, r);
        update(l, it2->second);
        col[v].insert(mp(l, r)), s.insert((node){l, r, v});
    }

    void erase(int l, int r, int v, int flag)
    {
        std::set<pair>::iterator it1 = col[v].upper_bound(mp(l, r));
        std::set<pair>::iterator it2 = --(--col[v].upper_bound(mp(l, r)));
        if (it1 != col[v].end()) update(it1->first, it2->second);
        ;
        if (l != flag) update(l, l - 1);
        col[v].erase(mp(l, r)), s.erase((node){l, r, v});
    }

    void cut(int l, int r, int v, int p)
    {
        s.erase((node){l, r, v}), col[v].erase(mp(l, r));
        s.insert((node){l, p, v}), col[v].insert(mp(l, p));
        s.insert((node){p + 1, r, v}), col[v].insert(mp(p + 1, r));
    }

    void assign(int l, int r, int v)
    {
        It it = s.lower_bound((node){l, l - 1, 0});
        if (it->l <= l && r <= it->r)
        {
            int l1 = it->l, r1 = it->r, v1 = it->v;
            if (l1 < l) cut(l1, r1, v1, l - 1);
            if (r < r1) cut(l, r1, v1, r);
            erase(l, r, v1, l);
        }
        else
        {
            while (it != s.end() && it->l <= r)
            {
                int l1 = it->l, r1 = it->r, v1 = it->v;
                ++it;
                if (l <= l1 && r1 <= r)
                    erase(l1, r1, v1, l);
                else
                {
                    if (l1 < l && l <= r1 && r1 <= r)
                        cut(l1, r1, v1, l - 1), erase(l, r1, v1, l);
                    if (l <= l1 && l1 <= r && r < r1)
                        cut(l1, r1, v1, r), erase(l1, r, v1, l);
                }
            }
        }
        insert(l, r, v);
    }
} tr;

struct BIT
{
    int c[MaxN << 1];
    int lowbit(int x) { return x & (-x); }
    void modify(int x, int val)
    {
        while (x <= n)
            c[x] += val, x += lowbit(x);
    }
    int query(int x)
    {
        int ret = 0;
        while (x)
            ret += c[x], x -= lowbit(x);
        return ret;
    }
} T;

int cmp1(change a, change b) { return a.pre < b.pre; }
int cmp2(query a, query b) { return a.l < b.l; }

char get()
{
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
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

void solve(int l, int r, int cl, int cr, int ql, int qr)
{
    if (l >= r || cl > cr) return;
    int mid = (l + r) >> 1, midc = cl - 1, midq = ql - 1, now = cl;
    for (int i = cl; i <= cr; i++)
        if (c[i].tim <= mid) midc = i;
    for (int i = ql; i <= qr; i++)
        if (q[i].tim <= mid) midq = i;
    solve(l, mid, cl, midc, ql, midq);
    solve(mid + 1, r, midc + 1, cr, midq + 1, qr);
    std::sort(c + cl, c + midc + 1, cmp1);
    std::sort(q + midq + 1, q + qr + 1, cmp2);
    for (int i = midq + 1; i <= qr; i++)
    {
        while (now <= midc && c[now].pre < q[i].l)
            T.modify(c[now].pos, c[now].v), ++now;
        ans[q[i].id] += T.query(q[i].r) - T.query(q[i].l - 1);
    }
    for (int i = cl; i < now; i++)
        T.modify(c[i].pos, -c[i].v);
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), vec.push_back(a[i]);
    for (int i = 1; i <= m; i++)
    {
        op[i] = read(), l[i] = read(), r[i] = read();
        if (op[i] == 1) val[i] = read(), vec.push_back(val[i]);
    }
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end()), len = vec.size();
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
    tr.init();
    for (int i = 1; i <= m; i++)
    {
        if (op[i] == 1)
        {
            val[i] = std::lower_bound(vec.begin(), vec.end(), val[i]) - vec.begin() + 1;
            tr.assign(l[i], r[i], val[i]);
        }
        else
            q[++cntq] = {++cnt, l[i], r[i], cntq};
    }
    solve(1, cnt, 1, cntc, 1, cntq);
    for (int i = 1; i <= cntq; i++)
        printf("%d\n", ans[i]);
    return 0;
}