#include <bits/stdc++.h>

#define It std::set<node>::iterator
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

struct node
{
    int l, r;
    mutable int val;
    node(int l, int r = -1, int val = 0) : l(l), r(r), val(val) {}
    bool operator<(node x) const { return l < x.l; }
};

struct ChthollyTree
{
    std::set<node> s;
    It split(int mid)
    {
        It it = s.lower_bound(node(mid));
        if (it != s.end() && it->l == mid)
            return it;
        --it;
        int l = it->l, r = it->r, val = it->val;
        s.erase(it), s.insert(node(l, mid - 1, val));
        return s.insert(node(mid, r, val)).first;
    }
    void assign(int l, int r, int val)
    {
        It R = split(r + 1), L = split(l);
        s.erase(L, R), s.insert(node(l, r, val));
    }
    int query_cnt(int l, int r)
    {
        int ans = 0;
        It R = split(r + 1), L = split(l);
        while (L != R)
            ans += L->val * (L->r - L->l + 1), L++;
        return ans;
    }
    void cure(int l1, int r1, int l2, int r2)
    {
        int a = query_cnt(l1, r1);
        assign(l1, r1, 0);
        It R = split(r2 + 1), L = split(l2);
        while (L != R)
        {
            if (L->val == 0)
            {
                if (a >= (L->r - L->l + 1))
                    a -= (L->r - L->l + 1), L->val = 1;
                else
                {
                    assign(L->l, L->l + a - 1, 1);
                    break;
                }
            }
            ++L;
        }
    }
    int query_con(int l, int r)
    {
        int ans = 0, cnt = 0;
        It R = split(r + 1), L = split(l);
        while (L != R)
        {
            if (L->val == 1)
                cnt = 0;
            else
                cnt += (L->r - L->l + 1), ans = std::max(ans, cnt);
            L++;
        }
        return ans;
    }
} Ct;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m), Ct.s.insert(node(1, n, 1));
    while (m--)
    {
        int op, l, r, l1, r1;
        scanf("%d", &op), ++op;
        if (op == 1)
        {
            scanf("%d%d", &l, &r);
            Ct.assign(l, r, 0);
        }
        else if (op == 2)
        {
            scanf("%d%d%d%d", &l, &r, &l1, &r1);
            Ct.cure(l, r, l1, r1);
        }
        else
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", Ct.query_con(l, r));
        }
    }
    return 0;
}
