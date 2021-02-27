#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e3 + 10;
const int MaxM = 5e5 + 10;

struct Modify
{
    int x, y;
} p[MaxM];

struct Query
{
    int x, y, t, id;
} q[MaxM], lq[MaxM], rq[MaxM];

std::vector<int> v[MaxM << 2];
std::pair<int, int> st[MaxM];
int cnt, ans[MaxM], tim[MaxN][MaxN];
int n, m, top, num, fa[MaxN], rk[MaxN];

int getf(int x)
{
    if (x == fa[x])
        return fa[x];
    return getf(fa[x]);
};

void del(int cur)
{
    while (top > cur)
    {
        std::pair<int, int> pre = st[top--];
        fa[pre.first] = pre.first;
        rk[pre.first] = pre.second;
    }
}

void merge(int x, int y)
{
    x = getf(x), y = getf(y);
    if (x == y) return;
    if (rk[x] < rk[y]) std::swap(x, y);
    fa[y] = x, st[++top] = std::make_pair(y, rk[y]);
    if (rk[x] == rk[y])
        st[++top] = std::make_pair(x, ++rk[x]);
}

void modify(int id, int l, int r, int ql, int qr, int pos)
{
    if (ql <= l && r <= qr)
        return (void)v[id].push_back(pos);
    int mid = (l + r) >> 1;
    if (ql <= mid) modify(id << 1, l, mid, ql, qr, pos);
    if (qr > mid) modify(id << 1 | 1, mid + 1, r, ql, qr, pos);
}

void solve(int id, int l, int r, int st, int ed)
{
    if(st > ed) return; int cur = top;
    for(int i = 0; i < v[id].size(); i++)
        merge(p[v[id][i]].x, p[v[id][i]].y);
    if(l == r)
    {
        for(int i = st; i <= ed; i++)
            ans[q[i].id] = (getf(q[i].x) == getf(q[i].y)); 
        return;
    }
    int mid = (l + r) >> 1, lt = 0, rt = 0;
    for(int i = st; i <= ed; i++)
        if(q[i].t <= mid) lq[++lt] = q[i];
        else rq[++rt] = q[i];
    for(int i = 1; i <= lt; i++) q[st + i - 1] = lq[i];
    for(int i = 1; i <= rt; i++) q[st + i + lt - 1] = rq[i];
    solve(id << 1, l, mid, st, st + lt - 1);
    solve(id << 1 | 1, mid + 1, r, st + lt, ed), del(cur);
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

signed main()
{
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        fa[i] = i, rk[i] = 1;
    for(int i = 1; i <= m; i++)
    {
        int op = read(), x = read(), y = read();
        if(x > y) std::swap(x, y);
        if(op == 0) tim[x][y] = i;
        else if(op == 1) 
            modify(1, 1, m, tim[x][y], i, ++cnt),
            p[cnt] = (Modify){x, y}, tim[x][y] = 0;
        else q[++num] = (Query){x, y, i, num};
    }
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            if(tim[i][j]) 
                modify(1, 1, m, tim[i][j], m, ++cnt),
                    p[cnt] = (Modify){i, j};
    solve(1, 1, m, 1, num);
    for(int i = 1; i <= num; i++)
        puts(ans[i] ? "Y" : "N");
    return 0;
}
