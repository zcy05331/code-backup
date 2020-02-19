// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int left;
    int right;
    int min;
    int max;
    int sum;
    int delta;
    int mul;

} tree[800010];
int x[200010];
int k;
int build(int id, int l, int r)
{
    tree[id].left = l;
    tree[id].right = r;
    if (l == r)
    {
        tree[id].sum = x[l] % k;
        tree[id].min = x[l] % k;
        tree[id].max = x[l] % k;
        tree[id].mul = 1;
    }
    else
    {
        int mid = (tree[id].left + tree[id].right) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id].max = max(tree[id * 2].max, tree[id * 2 + 1].max) % k;
        tree[id].sum = tree[id * 2].sum % k + tree[id * 2 + 1].sum % k;
        tree[id].min = min(tree[id * 2].min, tree[id * 2 + 1].min) % k;
        tree[id].mul = 1;
    }
}

int pushdown(int id)
{
    tree[id * 2].sum = (tree[id * 2].sum * tree[id].mul + tree[id].delta * (tree[id * 2].right - tree[id * 2].left + 1)) % k;
    tree[id * 2 + 1].sum = (tree[id * 2 + 1].sum * tree[id].mul + tree[id].delta * (tree[id * 2 + 1].right - tree[id * 2 + 1].left + 1)) % k;

    tree[id * 2].max = (tree[id * 2].max * tree[id].mul + tree[id].delta) % k;
    tree[id * 2 + 1].max = (tree[id * 2 + 1].max * tree[id].mul + tree[id].delta) % k;

    tree[id * 2].min = (tree[id * 2].min * tree[id].mul + tree[id].delta) % k;
    tree[id * 2].min = (tree[id * 2].min * tree[id].mul + tree[id].delta) % k;

    tree[id * 2].mul = (tree[id].mul * tree[id * 2].mul) % k;
    tree[id * 2 + 1].mul = (tree[id].mul * tree[id * 2 + 1].mul) % k;

    tree[id * 2].delta = (tree[id * 2].delta * tree[id].mul + tree[id].delta) % k;
    tree[id * 2 + 1].delta = (tree[id * 2 + 1].delta * tree[id].mul + tree[id].delta) % k;

    tree[id].mul = 1;
    tree[id].delta = 0;
}
int mul(int id, int l, int r, int muls)
{
    if (tree[id].left >= l && tree[id].right <= r)
    {
        tree[id].delta = (tree[id].delta * muls) % k, tree[id].max = (tree[id].max * muls) % k, tree[id].min = (tree[id].min * muls) % k, tree[id].sum = (tree[id].sum * muls) % k;
        tree[id].mul *= muls;
        return 0;
    }
    else
    {
        pushdown(id);
        int mid = (tree[id].left + tree[id].right) / 2;
        if (r <= mid)
            mul(id * 2, l, r, muls);
        else if (l > mid)
            mul(id * 2 + 1, l, r, muls);
        else
        {
            mul(id * 2, l, mid, muls);
            mul(id * 2 + 1, mid + 1, r, muls);
        }
        tree[id].max = max(tree[id * 2].max, tree[id * 2 + 1].max) % k;
        tree[id].sum = (tree[id * 2].sum + tree[id * 2 + 1].sum) % k;
        tree[id].min = min(tree[id * 2].min, tree[id * 2 + 1].min) % k;
    }
}
int add(int id, int l, int r, int adds)
{
    if (tree[id].left >= l && tree[id].right <= r)
    {
        tree[id].delta += adds, tree[id].max += adds, tree[id].min += adds;
        tree[id].sum += adds * (tree[id].right - tree[id].left + 1) % k;
        return 0;
    }
    else
    {
        pushdown(id);
        int mid = (tree[id].left + tree[id].right) / 2;
        if (r <= mid)
            add(id * 2, l, r, adds);
        else if (l > mid)
            add(id * 2 + 1, l, r, adds);
        else
        {
            add(id * 2, l, mid, adds);
            add(id * 2 + 1, mid + 1, r, adds);
        }
        tree[id].max = max(tree[id * 2].max, tree[id * 2 + 1].max) % k;
        tree[id].sum = (tree[id * 2].sum + tree[id * 2 + 1].sum) % k;
        tree[id].min = min(tree[id * 2].min, tree[id * 2 + 1].min) % k;
    }
}
node query(int id, int l, int r)
{
    if (tree[id].left == l && tree[id].right == r)
    {
        return tree[id];
    }
    else
    {
        node ans;
        pushdown(id);
        int mid = (tree[id].left + tree[id].right) / 2;
        if (r <= mid)
            return query(id * 2, l, r);
        else if (l > mid)
            return query(id * 2 + 1, l, r);
        else
        {
            node r1, r2;
            r1 = query(id * 2, l, mid);
            r2 = query(id * 2 + 1, mid + 1, r);
            //printf("r1-sum=%d r2-sum=%d\n",r1.sum,r2.sum);
            ans.sum = (r1.sum + r2.sum) % k;
            ans.max = max(r1.max, r2.max) % k;
            ans.min = min(r1.min, r2.min) % k;
            return ans;
        }
    }
}
int main()
{
    int n, m;
    int a, b, c;
    scanf("%d%d", &n, &k);
    int t = 0;
    int len = 0;
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        char op;
        cin >> op;
        if (op == 'A')
        {
            ++len;
            int num;
            scanf("%d", &num);
            add(1, len, len, (num + t) % k);
        }
        else
        {
            int l;
            scanf("%d", &l);
            t = query(1, len - l + 1, len).max % k;
            printf("%d\n", t);
        }
    }
    return 0;
}