#include <iostream>
#include <cstdio>

#define Max 500005

using namespace std;

inline char gc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc getchar
inline int read()
{
    int x = 0;
    char ch = gc();
    bool positive = 1;
    for (; !isdigit(ch); ch = gc())
        if (ch == '-')
            positive = 0;
    for (; isdigit(ch); ch = gc())
        x = x * 10 + ch - '0';
    return positive ? x : -x;
}

inline void write(int x)
{
    if (x < 0)
        x = -x, putchar('-');
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x)
{
    write(x);
    puts("");
} 

struct Tree
{
    int id, ls, rs, num, minn;

} ct[Max * 50]; 
int n, m, l, r, cnt, a[Max], vis[Max], last[Max], root[Max];

inline Tree update(int id, Tree l, Tree r)
{
    Tree ans;
    ans.id = id;
    ans.ls = l.id;
    ans.rs = r.id;
    if (l.minn < r.minn)
    {
        ans.num = l.num;
        ans.minn = l.minn;
    }
    else
    {
        ans.num = r.num;
        ans.minn = r.minn;
    }
    return ans;
}

inline void build(int &now, int l, int r)
{
    now = ++cnt;
    ct[now].id = cnt;
    if (l == r)
    {
        ct[now].num = l;
        ct[now].minn = 1e9;
        return;
    }
    int mid = (l + r) >> 1;
    build(ct[now].ls, l, mid);
    build(ct[now].rs, mid + 1, r);
    ct[now] = update(now, ct[ct[now].ls], ct[ct[now].rs]);
}

inline void change(int &now, int old, int l, int r, int id, int num)
{
    now = ++cnt;
    ct[now] = ct[old];
    ct[now].id = cnt;
    if (l == r)
    {
        ct[now].minn = num;
        return;
    }
    int mid = (l + r) >> 1;
    if (id <= mid)
    {
        change(ct[now].ls, ct[old].ls, l, mid, id, num);
    }
    else
    {
        change(ct[now].rs, ct[old].rs, mid + 1, r, id, num);
    }
    ct[now] = update(now, ct[ct[now].ls], ct[ct[now].rs]);
}

inline Tree query(int now, int l, int r, int L, int R)
{ 
    if (l >= L && r <= R)
    {
        return ct[now];
    }
    int mid = (l + r) >> 1;
    if (R <= mid)
    {
        return query(ct[now].ls, l, mid, L, R);
    }
    else
    {
        if (L > mid)
        {
            return query(ct[now].rs, mid + 1, r, L, R);
        }
        else
        {
            return update(1, query(ct[now].ls, l, mid, L, R), query(ct[now].rs, mid + 1, r, L, R));
        }
    }
}

int main()
{
    n = read();
    build(root[0], 1, n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        root[i] = root[i - 1];
        if (vis[a[i]])
        {
            change(root[i], root[i], 1, n, vis[a[i]], 1e9);
            last[a[i]] = vis[a[i]];
            change(root[i], root[i], 1, n, i, last[a[i]]);
            vis[a[i]] = i;
        }
        else
        {
            vis[a[i]] = i;
            change(root[i], root[i], 1, n, i, 0);
        }
    }
    m = read();
    for (int i = 1; i <= m; i++)
    {
        l = read();
        r = read();
        Tree ans = query(root[r], 1, n, l, r);
        if (ans.minn >= l)
        { 
            puts("0");
        }
        else
        {
            writeln(a[ans.num]);
        }
    }
    return 0;
}