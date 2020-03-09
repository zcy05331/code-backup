#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

ll n, ans;
char s[MaxN];

struct SuffixAutomaton
{
    struct state
    {
        int len, link;
        std::unordered_map<int, int> next;
    };
    int size, last;
    state st[MaxN << 1];
    void sam_init() { size = last = 1; }
    void sam_clear()
    {
        for(int i = 1; i <= size; i++)
            st[i].len = st[i].link = 0, st[i].next.clear();
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
                st[clone].next = st[q].next;
                st[clone].link = st[q].link, st[clone].len = st[p].len + 1;
                while (p && st[p].next[c] == q)
                    st[p].next[c] = clone, p = st[p].link;
                st[cur].link = st[q].link = clone;
            }
        }
        last = cur, ans += st[cur].len - st[st[cur].link].len;
    }
} sam;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        n = ans = 0;
        sam.sam_clear(), sam.sam_init();
        scanf("%s", s + 1), n = strlen(s + 1);
        for (int i = 1; i <= n; i++)
            sam.sam_extend(s[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
