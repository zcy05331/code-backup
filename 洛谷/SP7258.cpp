#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

int n;
char s[MaxN];

struct SuffixAutomaton
{
    struct state
    {
        int next[30];
        int len, link;
    };
    state st[MaxN << 1];
    int size, last, siz[MaxN];
    void sam_init() { size = last = 1; }
    void get(int u, unsigned int k)
    {
        --k;
        if (!k) return;
        for (int i = 0; i < 26; i++)
        {
            int v = st[u].next[i];
            if (v)
            {
                if (k > siz[v])
                    k -= siz[v];
                else
                {
                    putchar(i + 'a'), get(v, k);
                    break;
                }
            }
        }
    }
    void dfs(int u)
    {
        if (siz[u]) return;
        siz[u] = 1;
        for (int i = 0; i < 26; i++)
        {
            int v = st[u].next[i];
            if (v)
                dfs(v), siz[u] += siz[v];
        }
    }
    void sam_extend(int c)
    {
        int cur = ++size, p = last;
        st[cur].len = st[p].len + 1;
        while (p && !st[p].next[c])
            st[p].next[c] = cur, p = st[p].link;
        if (p == 0)
            st[cur].link = 1;
        else
        {
            int q = st[p].next[c];
            if (st[q].len == st[p].len + 1)
                st[cur].link = q;
            else
            {
                int clone = ++size;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].len = st[p].len + 1, st[clone].link = st[q].link;
                while (p && st[p].next[c] == q)
                    st[p].next[c] = clone, p = st[p].link;
                st[cur].link = st[q].link = clone;
            }
        }
        last = cur;
    }
} sam;

int main()
{
    int T;
    sam.sam_init();
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        sam.sam_extend(s[i] - 'a');
    scanf("%d", &T), sam.dfs(1);
    while (T--)
    {
        int k;
        scanf("%d", &k);
        sam.get(1, k + 1), puts("");
    }
    return 0;
}
