#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 6e5 + 10;

int n, m, cnt, s[MaxN], root[MaxN];
int ch[MaxN << 5][2], last[MaxN << 5];

void insert(int rt, int pre, int pos, int dep)
{
    if(dep < 0)
        return (void) (last[rt] = pos);
    int c = !!(s[pos] & (1 << dep));
    ch[rt][c] = ++cnt;
    if(pre) ch[rt][c ^ 1] = ch[pre][c ^ 1];
    insert(ch[rt][c], ch[pre][c], pos, dep - 1);
    last[rt] = std::max(last[ch[rt][0]], last[ch[rt][1]]);
}

int query(int rt, int val, int dep, int l)
{
    if(dep < 0) return s[last[rt]] ^ val;
    int c = (!!(val & (1 << dep))) ^ 1;
    if(last[ch[rt][c]] >= l)
        return query(ch[rt][c], val, dep - 1, l);
    return query(ch[rt][c ^ 1], val, dep - 1, l);
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

int main()
{   
    n = read(), m = read(), last[0] = -1;
    root[0] = cnt = 1, insert(root[0], 0, 0, 23);
    for(int i = 1, x; i <= n; i++)
    {
        x = read(), s[i] = s[i - 1] ^ x, root[i] = ++cnt;
        insert(root[i], root[i - 1], i, 23);
    }
    char op[2];
    while(m--)
    {
        int l, r, x;
        scanf("%s", op + 1);
        if(op[1] == 'A')
        {
            x = read(), root[++n] = ++cnt, s[n] = s[n - 1] ^ x;
            insert(root[n], root[n - 1], n, 23);
        }
        else
        {
            l = read(), r = read(), x = read();
            printf("%d\n", query(root[r - 1], s[n] ^ x, 23, l - 1));
        }
    }
    return 0;
}
