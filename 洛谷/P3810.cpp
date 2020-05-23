#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

int n, m, nowd, root;

struct node
{
    int lc, rc, val, sum;
    int d[3], max[3], min[3];
    bool operator<(const node &x) const { return d[nowd] < x.d[nowd]; }
};

node a[MaxN];


int main()
{   

    return 0;
}
