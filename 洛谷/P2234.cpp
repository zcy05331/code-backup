//Treap by little_sun
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int l;    //?????
    int r;    //?????
    int v;    //value
    int size; //????��[??????]
    int rnd;  //????
    int w;    //??????????
} tree[100005];
int n, size, root, ans;
void update(int k) //?????????
{
    tree[k].size = tree[tree[k].l].size + tree[tree[k].r].size + tree[k].w;
}
void rturn(int &k) //????
{
    int t = tree[k].l;
    tree[k].l = tree[t].r;
    tree[t].r = k;
    tree[t].size = tree[k].size;
    update(k);
    k = t;
}
void lturn(int &k) //????
{
    int t = tree[k].r;
    tree[k].r = tree[t].l;
    tree[t].l = k;
    tree[t].size = tree[k].size;
    update(k);
    k = t;
}
void insert(int &k, int x) //????
{
    if (k == 0)
    {
        size++;
        k = size;
        tree[k].size = tree[k].w = 1;
        tree[k].v = x;
        tree[k].rnd = rand();
        return;
    }
    tree[k].size++;
    if (tree[k].v == x)
        tree[k].w++;
    else if (x > tree[k].v)
    {
        insert(tree[k].r, x);
        if (tree[tree[k].r].rnd < tree[k].rnd)
            lturn(k);
    }
    else
    {
        insert(tree[k].l, x);
        if (tree[tree[k].l].rnd < tree[k].rnd)
            rturn(k);
    }
}
void del(int &k, int x) //???
{
    if (k == 0)
        return;
    if (tree[k].v == x)
    {
        if (tree[k].w > 1)
        {
            tree[k].w--;
            tree[k].size--;
            return;
        }
        if (tree[k].l * tree[k].r == 0)
            k = tree[k].l + tree[k].r;
        else if (tree[tree[k].l].rnd < tree[tree[k].r].rnd)
            rturn(k), del(k, x);
        else
            lturn(k), del(k, x);
    }
    else if (x > tree[k].v)
    {
        tree[k].size--;
        del(tree[k].r, x);
    }
    else
    {
        tree[k].size--;
        del(tree[k].l, x);
    }
}
int query_rank(int k, int x)
{
    if (k == 0)
        return 0;
    if (tree[k].v == x)
        return tree[tree[k].l].size + 1;
    else if (x > tree[k].v)
        return tree[tree[k].l].size + tree[k].w + query_rank(tree[k].r, x);
    else
        return query_rank(tree[k].l, x);
}
int query_num(int k, int x)
{
    if (k == 0)
        return 0;
    if (x <= tree[tree[k].l].size)
        return query_num(tree[k].l, x);
    else if (x > tree[tree[k].l].size + tree[k].w)
        return query_num(tree[k].r, x - tree[tree[k].l].size - tree[k].w);
    else
        return tree[k].v;
}
void query_pro(int k, int x)
{
    if (k == 0)
        return;
    if (tree[k].v <= x)
    {
        ans = k;
        query_pro(tree[k].r, x);
    }
    else
        query_pro(tree[k].l, x);
}
void query_sub(int k, int x)
{
    if (k == 0)
        return;
    if (tree[k].v >= x)
    {
        ans = k;
        query_sub(tree[k].l, x);
    }
    else
        query_sub(tree[k].r, x);
}
int main()
{
    scanf("%d", &n);
    int cnt = 0;
    insert(root, 2000000);
    insert(root, -2000000);
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        query_sub(root, tmp);
        int sub = tree[ans].v;
        query_pro(root, tmp);
        int pro = tree[ans].v;
        if (i == 1)
            cnt += tmp;
        else
            cnt += std::min( abs(tmp - sub), abs(pro - tmp) );
        insert(root, tmp);
    }
    printf("%d", cnt);
    return 0;
}
