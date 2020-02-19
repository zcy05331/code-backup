#include <bits/stdc++.h>

const int MaxN = 100010;

struct size_balanced_tree
{
    int key[MaxN], lc[MaxN], rc[MaxN], size[MaxN];
    int root, cnt;

    void left_turn(int &x)
    {
        int y = rc[x];
        rc[x] = lc[y];
        lc[y] = x;
        size[y] = size[x];
        size[x] = size[lc[x]] + size[rc[x]] + 1;
        x = y;
    }

    void right_turn(int &x)
    {
        int y = lc[x];
        lc[x] = rc[y];
        rc[y] = x;
        size[y] = size[x];
        size[x] = size[lc[x]] + size[rc[x]] + 1;
        x = y;
    }

    void maintain(int &x, bool flag)
    {
        if (!flag)
        {
            if (size[lc[lc[x]]] > size[rc[x]])
                right_turn(x);
            else if (size[rc[lc[x]]] > size[rc[x]])
                left_turn(lc[x]), right_turn(x);
            else
                return;
        }
        else
        {
            if (size[rc[rc[x]]] > size[lc[x]])
                left_turn(x);
            else if (size[lc[rc[x]]] > size[lc[x]])
                right_turn(rc[x]), left_turn(x);
            else
                return;
        }
        maintain(lc[x], false);
        maintain(rc[x], true);
        maintain(x, true);
        maintain(x, false);
    }

    void insert(int &x, int val)
    {
        if (!x)
        {
            x = ++cnt;
            lc[x] = rc[x] = 0;
            size[x] = 1;
            key[x] = val;
        }
        else
        {
            size[x]++;
            if (val < key[x])
                insert(lc[x], val);
            else
                insert(rc[x], val);
            maintain(x, val >= key[x]);
        }
    }

    int del(int &x, int val)
    {
        size[x]--;
        if (val == key[x] || (val < key[x] && lc[x] == 0) || (val > key[x] && rc[x] == 0))
        {
            int y = key[x];
            if (lc[x] == 0 || rc[x] == 0)
                x = lc[x] + rc[x];
            else
                key[x] = del(lc[x], key[x] + 1);
            return y;
        }
        else
        {
            if (val < key[x])
                return del(lc[x], val);
            else
                return del(rc[x], val);
        }
    }

    int getmin()
    {
        int i;
        for (i = root; lc[i]; i = lc[i])
            ;
        return key[i];
    }

    int getmax()
    {
        int i;
        for (i = root; rc[i]; i = rc[i])
            ;
        return key[i];
    }

    int query_num(int &x, int rank)
    {
        if (size[lc[x]] + 1 == rank)
            return key[x];
        else if (rank <= size[lc[x]])
            return query_num(lc[x], rank);
        else
            return query_num(rc[x], rank - size[lc[x]] - 1);
    }

    int query_rank(int &x, int val)
    {
        if (!x)
            return 1;
        int ans = 0;
        if (val <= key[x])
            ans = query_rank(lc[x], val);
        else
            ans = size[lc[x]] + 1 + query_rank(rc[x], val);
        return ans;
    }

    int query_pre(int &x, int val)
    {
        if (!x)
            return val;
        int ans;
        if (key[x] >= val)
            ans = query_pre(lc[x], val);
        else
        {
            ans = query_pre(rc[x], val);
            if (ans == val)
                ans = key[x];
        }
        return ans;
    }

    int query_sub(int &x, int val)
    {
        if (!x)
            return val;
        int ans;
        if (val >= key[x])
            ans = query_sub(rc[x], val);
        else
        {
            ans = query_sub(lc[x], val);
            if (ans == val)
                ans = key[x];
        }
        return ans;
    }
}T;

int main()
{
    int n;
    scanf("%d", &n);
    T.root = T.cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1)
            T.insert(T.root, x);
        if (op == 2)
            T.del(T.root, x);
        if (op == 3)
            printf("%d\n", T.query_rank(T.root, x));
        if (op == 4)
            printf("%d\n", T.query_num(T.root, x));
        if (op == 5)
            printf("%d\n", T.query_pre(T.root, x));
        if (op == 6)
            printf("%d\n", T.query_sub(T.root, x));
    }
    return 0;
}