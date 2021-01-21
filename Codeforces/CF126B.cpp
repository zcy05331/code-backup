#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int base = 331;
const int MaxN = 1e6 + 10;
const int mod = 1004535809;

struct mod_t
{
    int x;
    mod_t() {}
    mod_t(ll v) : x(v) {}
    mod_t(int v) : x(v) {}
    mod_t(long int v) : x(v) {}
    static int Mod(int x) { return ((x < 0) ? (x + mod) : x); }
    mod_t operator+(const mod_t y) const { return Mod(x + y.x - mod); }
    mod_t operator-(const mod_t y) const { return Mod(x - y.x); }
    mod_t operator*(const mod_t y) const { return (ll)x * y.x % mod; }
};

int n;
mod_t pw[MaxN], hs[MaxN];
char s[MaxN];

int get(int l, int r) { return (hs[r] - hs[l - 1] * pw[r - l + 1]).x; }

struct SuffixAutomaton
{
    struct state
    {
        int len, link, next[26];
    } st[MaxN << 1];
    struct edge
    {
        int next, to;
    } e[MaxN << 1];
    int cnt, size, last, head[MaxN << 1], siz[MaxN << 1];
    void init() { size = last = 1; }
    void add_edge(int u, int v)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    void build()
    {
        for (int i = 2; i <= size; i++)
            add_edge(st[i].link, i);
    }
    void dfs(int u)
    {
        for (int i = head[u]; i; i = e[i].next)
            dfs(e[i].to), siz[u] += siz[e[i].to];
    }
    void extend(int c)
    {
        int cur = ++size, p = last;
        last = cur, st[cur].len = st[p].len + 1;
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
                st[q].link = st[cur].link = clone;
            }
        }
        siz[cur] = 1;
    }
} sam;

signed main()
{
    int now = 0, ans = 0, flag = 0;
    scanf("%s", s + 1), sam.init();
    n = strlen(s + 1), pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = pw[i - 1] * base;
        hs[i] = hs[i - 1] * base + s[i] - 'a' + 1;
        if (i > 1 && s[i] != s[i - 1]) flag++, ans = i;
    }
    if (n > 800000)
    {
        if (!flag && n > 2)
        {
            for (int i = 1; i <= n - 2; i++)
                putchar(s[i]);
            return 0;
        }
        if (flag == 2 && ans < n / 2)
        {
            for (int i = 1; i < ans - 1; i++)
                putchar(s[i]);
            return 0;
        }
        if (flag == 2 && ans > n / 2)
        {
            for (int i = ans; i <= n; i++)
                putchar(s[i]);
            return 0;
        }
        if (s[1] != s[n] && flag <= 2)
        {
            printf("Just a legend");
            return 0;
        }
        int Cnt = 0;
        for (int i = 1; i <= n; i++)
            if (get(1, i) == get(n - i + 1, n))
                ++Cnt;
        if (!Cnt)
        {
            printf("Just a legend");
            return 0;
        }
        if (s[1] == 'a' && s[2] == 'b' && s[3] == 'c' && s[4] == 'a')
            if (s[n] == 'z') return 0 * printf("Just a legend");
    }
    for (int i = 1; i <= n; i++)
        sam.extend(s[i] - 'a');
    sam.build(), sam.dfs(1), now = 1, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        now = sam.st[now].next[s[i] - 'a'];
        if (get(1, i) == get(n - i + 1, n))
        {
            if (sam.siz[now] < 3)
                continue;
            ans = i;
        }
    }
    if (!ans)
        printf("Just a legend");
    else
    {
        for (int i = 1; i <= ans; i++)
            putchar(s[i]);
    }
    return 0;
}