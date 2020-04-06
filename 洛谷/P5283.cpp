#include <bits/stdc++.h>

#define R register
#define ll long long
#define int unsigned
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 7e5 + 10;
const int Max = MaxN << 6;

struct node
{
    int l, r, pos;
    int maxp, val;
    bool operator<(node x) const { return val < x.val; }
};

int n, k;
int a[MaxN], s[MaxN], root[MaxN];
std::priority_queue<node> q;

struct trie
{
    int cnt, id[Max], siz[Max], ch[Max][2];
    void insert(int &rt, int pre, int idx, int val, signed dep)
    {
        int c = ((val >> dep) & 1);
        rt = ++cnt, siz[rt] = siz[pre] + 1;
        ch[rt][c ^ 1] = ch[pre][c ^ 1];
        if(dep < 0) return (void) (id[rt] = idx);   
        insert(ch[rt][c], ch[pre][c], idx, val, dep - 1);
    }
    int query(int u, int v, int val, signed dep)
    {
        if(dep < 0) return id[v];
        int c = ((val >> dep) & 1) ^ 1;
        if(siz[ch[v][c]] - siz[ch[u][c]])
            return query(ch[u][c], ch[v][c], val, dep - 1);
        else return query(ch[u][c ^ 1], ch[v][c ^ 1], val, dep - 1); 
    }
    void Query(int l, int r, int val, int &pos, int &num){pos = query(root[l - 1], root[r], val, 31), num = s[pos - 1] ^ val;}
} T;

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

signed main()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read(), s[i] = s[i - 1] ^ a[i];
        T.insert(root[i], root[i - 1], i, s[i - 1], 31);
    }
    for (int i = 1; i <= n; i++)
    {
        int pos, val;
        T.Query(1, i, s[i], pos, val);
        q.push({1, i, i, pos, val});
    }
    ll ans = 0;
    for(int i = 1; i <= k; i++)
    {
        node x = q.top();
        q.pop(), ans += x.val;
        if(x.maxp > x.l)
        {
            int pos, val;
            T.Query(x.l, x.maxp - 1, s[x.pos], pos, val);
            q.push({x.l, x.maxp - 1, x.pos, pos, val});
        }
        if(x.maxp < x.r)
        {
            int pos, val;
            T.Query(x.maxp + 1, x.r, s[x.pos], pos, val);
            q.push({x.maxp + 1, x.r, x.pos, pos, val});
        }
    }
    printf("%lld\n", ans);
    return 0;
}
