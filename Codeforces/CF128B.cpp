#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

int n, k;
char s[MaxN];

struct SuffixAutomaton
{
    struct edge
    {
        int next, to;
    };
    struct state
    {
        int len, link;
        int next[30];
    };
    edge e[MaxN << 1];
    state st[MaxN << 1];
    ll cnt, size, last, siz[MaxN], sum[MaxN], head[MaxN];
    void sam_init() { size = last = 1; }
    void add_edge(int u, int v)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    void sam_build()
    {
        for(int i = 2; i <= size; i++)
            add_edge(st[i].link, i);
    }
    void dfs(int u)
    {
        if(siz[u]) return;
        siz[u] = sum[u];
        for(int i = 1; i <= 26; i++)
        {
            int v = st[u].next[i];
            if(v)
                dfs(v), siz[u] += siz[v];
        }
    }
    void dfs1(int u)
    {
        for(int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            dfs1(v), sum[u] += sum[v];
        }
    }
    void get(int u, int k)
    {
        if(k <= 0) return;
        for(int i = 1; i <= 26; i++)
        {
            int v = st[u].next[i];
            if(!v) continue;
            if(k > siz[v]) 
                k -= siz[v];
            else
            {
                k -= sum[v], putchar(i + 96);
                return get(v, k);
            }
        }
    }
    void sam_extend(int c)
    {
        int cur = ++size, p = last;
        st[cur].len = st[p].len + 1;
        while(p && !st[p].next[c])
            st[p].next[c] = cur, p = st[p].link;
        if(!p)
            st[cur].link = 1;
        else
        {
            int q = st[p].next[c];
            if(st[q].len == st[p].len + 1)
                st[cur].link = q;
            else
            {
                int clone = ++size;
                memcpy(st[clone].next, st[q].next, sizeof st[q].next);
                st[clone].len = st[p].len + 1, st[clone].link = st[q].link;
                while(p && st[p].next[c] == q)
                    st[p].next[c] = clone, p = st[p].link;
                st[cur].link = st[q].link = clone;
            }
        }
        last = cur, sum[cur] = 1;
    }
}sam;

int main()
{   
    sam.sam_init();
    scanf("%s%d", s + 1, &k), n = strlen(s + 1);
    for(int i = 1; i <= n; i++)
        sam.sam_extend(s[i] - 'a' + 1);
    sam.sam_build(), sam.dfs1(1);
    sam.dfs(1), sam.siz[1]--;
    if(sam.siz[1] < k)
        return 0 * puts("No such line.");
    else sam.get(1, k);
    return 0; 
}
