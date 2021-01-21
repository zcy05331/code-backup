#include <bits/stdc++.h>

#define R register
#define ll long long
#define lc (id << 1)
#define rc (id << 1 | 1)
#define meow(cat...) fprintf(stderr, cat)
#define sum(A, B, Mod) (((A) + (B)) % (Mod))

const int MaxN = 5e5 + 10;

struct node
{
    int l, r, sum, max, ans;
    int maxl, minr, ansl, ansr;
};

char s[MaxN];
int n, q, len, a[MaxN];

struct SegmentTree
{
    node t[MaxN << 1];
    void pushup(int id)
    {
        t[id].sum = t[lc].sum + t[rc].sum;
        t[id].maxl = std::max(t[lc].maxl, t[lc].sum + t[rc].maxl);
        t[id].minr = std::min(t[rc].minr, t[rc].sum + t[lc].minr);
        t[id].max = std::max(t[lc].max + t[rc].sum, t[rc].max - t[lc].sum);
        t[id].ansl = std::max(std::max(t[lc].ansl, t[rc].ansl - t[lc].sum), t[lc].max + t[rc].maxl);
        t[id].ansr = std::max(std::max(t[rc].ansr, t[rc].sum + t[lc].ansr), t[rc].max - t[lc].minr);
        t[id].ans = std::max(std::max(t[lc].ans, t[rc].ansl - t[lc].minr), std::max(t[rc].ans, t[lc].ansr + t[rc].maxl));
    }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
        {
            t[id].sum = a[l], t[id].maxl = std::max(a[l], 0);
            t[id].minr = std::min(a[r], 0), t[id].ansl = t[id].ansr = 1;
            return (void)(t[id].ans = t[id].max = 1);
        }
        int mid = (l + r) >> 1;
        build(lc, l, mid), build(rc, mid + 1, r), pushup(id);
    }
    void modify(int id, int pos, int val)
    {
        if (t[id].l > pos || pos > t[id].r) return;
        if (t[id].l == t[id].r)
        {
            t[id].sum = a[pos], t[id].maxl = std::max(a[pos], 0);
            t[id].minr = std::min(a[pos], 0), t[id].ansl = t[id].ansr = 1;
            return (void)(t[id].ans = t[id].max = 1);
        }
        int mid = (t[id].l + t[id].r) >> 1;
        if (pos <= mid)
            modify(lc, pos, val);
        else if (pos > mid)
            modify(rc, pos, val);
        pushup(id);
    }
} T;

int main()
{
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1), len = (n - 1) * 2;
    for (int i = 1; i <= len; i++)
        a[i] = (s[i] == '(') ? 1 : -1;
    T.build(1, 1, len), printf("%d\n", T.t[1].ans);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r), std::swap(a[l], a[r]);
        T.modify(1, l, a[l]), T.modify(1, r, a[r]);
        printf("%d\n", T.t[1].ans);
    }
    return 0;
}