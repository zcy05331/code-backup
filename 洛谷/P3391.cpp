#include <bits/stdc++.h>

const int MaxN = 100010;

int n, m;
int root;

int f[MaxN], size[MaxN];
int rev[MaxN], ch[MaxN][2];

inline void pushup(int x)
{
    size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
}

void pushdown(int x)
{
    if(rev[x])
    {
        std::swap(ch[x][0], ch[x][1]);
        rev[ch[x][0]] ^= 1;
        rev[ch[x][1]] ^= 1;
        rev[x] = 0;
    }
        
}

void rotate(int x, int &k)
{
    int y = f[x], z = f[y], kind;
    if(ch[y][0] == x)
        kind = 1;
    else kind = 0;
    if(y == k)
        k = x;
    else 
    {
        if(ch[z][0] == y)
            ch[z][0] = x;
        else ch[z][1] = x;
    }
    ch[y][kind ^ 1] = ch[x][kind];
    f[ch[y][kind ^ 1]] = y;
    ch[x][kind] = y;
    f[y] = x;
    f[x] = z;
    pushup(x);
    pushup(y);
}

void splay(int x, int &k)
{
    while(x != k)
    {
        int y = f[x], z = f[y];
        if(y != k)
        {
            if((ch[y][0] == x) ^ (ch[z][0] == y))
                rotate(x, k);
            else 
                rotate(y, k);
        }
        rotate(x, k);
    }
}

void build(int l, int r, int fa)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;
    if (mid < fa)
        ch[fa][0] = mid;
    else 
        ch[fa][1] = mid;
    f[mid] = fa;
    size[mid] = 1;
    if(l == r)
        return;
    build(l, mid - 1, mid);
    build(mid + 1, r, mid);
    pushup(mid);
}

int find(int x, int k)
{   
    pushdown(x);
    int s = size[ch[x][0]];
    if(k == s + 1)
        return x;
    if(k <= s)
        return find(ch[x][0], k);
    else 
        return find(ch[x][1], k - s - 1);
}

void reverse(int l, int r)
{
    int x = find(root, l), y = find(root, r + 2);
    splay(x, root);
    splay(y, ch[x][1]);
    int z = ch[y][0];
    rev[z] ^= 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    root = (n + 3) / 2;
    build(1, n + 2, root);
    for(int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        reverse(l, r);
    }
    for(int i = 2; i <= n + 1; i++)
        printf("%d ", find(root, i) - 1);
    return 0;
}
