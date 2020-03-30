#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

char s[MaxN];
int n, ans[MaxN];

struct SuffixAutomaton
{
    struct state
    {
        int len, link;
        int next[30];
    };
    struct edge
    {
        int next, to;
    };
    edge e[MaxN << 1];
    state st[MaxN << 1];
    int cnt, size, last, head[MaxN], siz[MaxN];
    void sam_init() { size = last = 1; }
    void add_edge(int u, int v)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    void dfs(int u)
    {
        for(int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            dfs(v), siz[u] += siz[v];
        }
        ans[st[u].len] = std::max(siz[u], ans[st[u].len]);
    }
    void sam_build()
    {
        scanf("%s", s + 1);
        n = strlen(s + 1), sam_init();
        for(int i = 1; i <= n; i++)
            sam_extend(s[i] - 'a');
        for(int i = 2; i <= size; i++)
            add_edge(st[i].link, i);
    }
    void sam_extend(int c)
    {
        int cur = ++size, p = last;
        st[cur].len = st[p].len + 1, siz[cur]++;
        while(p && !st[p].next[c])
            st[p].next[c] = cur, p = st[p].link;
        if(!p)
            st[cur].link = 1;
        else
        {
            int q = st[p].next[c];
            if(st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else
            {
                int clone = ++size;
                memcpy(st[clone].next, st[q].next, sizeof st[q].next);
                st[clone].len = st[p].len + 1, st[clone].link = st[q].link;
                while(p && st[p].next[c] == q)
                    st[p].next[c] = clone, p = st[p].link;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
}sam;

int main()
{   
    sam.sam_build(), sam.dfs(1);
    for(int i = n; i; i--)
        ans[i] = std::max(ans[i + 1], ans[i]);
    for(int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
