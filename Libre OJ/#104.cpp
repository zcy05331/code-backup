#include <bits/stdc++.h>

#define ll long long
#define lc t[x].ch[0]
#define rc t[x].ch[1]
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;
const int inf = 1e9 + 7;

struct node
{
    int ch[2];
    int size, cnt, val, rnd;
};

int n, tot, root;

struct treap
{
    node t[MaxN << 2];
    void update(int x) { t[x].size = t[lc].size + t[rc].size + t[x].cnt; }
    void rotate(int &x, int c)
    {   
        int y = t[x].ch[c];
        t[x].ch[c] = t[y].ch[c ^ 1];
        t[y].ch[c ^ 1] = x, update(x), update(x = y);
    }
    void insert(int &x, int val)
    {
        if(!x) 
        {
            x = ++tot, t[x].size = t[x].cnt = 1;
            t[x].rnd = rand(), t[x].val = val;
            return;
        }
        ++t[x].size;
        if(t[x].val == val)
            return (void) (++t[x].cnt);
        int c = val > t[x].val;
        insert(t[x].ch[c], val);
        if(t[x].rnd > t[t[x].ch[c]].rnd)
            rotate(x, c);
    }
    void del(int &x, int val)
    {
        if(!x) return;
        if(t[x].val == val)
        {
            if(t[x].cnt > 1)
                return (void) (--t[x].cnt, --t[x].size);
            int c = t[lc].rnd > t[rc].rnd;
            if(!lc || !rc) x = lc + rc;
            else rotate(x, c), del(x, val);
        }
        else 
            --t[x].size, del(t[x].ch[val > t[x].val], val);
    }
    int query_rank(int x, int val)
    {
        if(!x) return 0;
        if(val == t[x].val) return t[lc].size;
        if(val < t[x].val)
             return query_rank(lc, val);
        else 
            return t[lc].size + t[x].cnt + query_rank(rc, val);
    }
    int query_val(int x, int val)
    {
        if(!x) return 0;
        if(val <= t[lc].size) 
            return query_val(lc, val);
        else if(val > t[lc].size + t[x].cnt)
            return query_val(rc, val - t[lc].size - t[x].cnt);
        else return t[x].val;
    }
    int query_pre(int x, int val)
    {
        if(!x) return -inf;
        if(val <= t[x].val)
            return query_pre(lc, val);
        else return std::max(t[x].val, query_pre(rc, val));
    }
    int query_sub(int x, int val)
    {
        if(!x) return inf;
        if(val >= t[x].val)
            return query_sub(rc, val);
        else return std::min(t[x].val, query_sub(lc, val));
    }
} T;
 
 inline int read()
 {
     int x = 0, f = 1;
     char ch = getchar();
     while(ch > '9' || ch < '0')
     {
         if(ch == '-')
             f = 0;
         ch = getchar();
     }
     while(ch <= '9' && ch >= '0') 
         x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
     return f ? x : (-x);
 }

int main()
{   
    n = read(), srand(19260817);
    while(n--)
    {
        int op = read(), x = read();
        if(op == 1) T.insert(root, x);
        else if(op == 2) T.del(root, x);
        else if(op == 3) printf("%d\n", T.query_rank(root, x) + 1);
        else if(op == 4) printf("%d\n", T.query_val(root, x));
        else if(op == 5) printf("%d\n", T.query_pre(root, x));
        else printf("%d\n", T.query_sub(root, x));
    }
    return 0;
}
