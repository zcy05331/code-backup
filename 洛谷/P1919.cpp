# include <bits/stdc++.h>
const int MaxN = 200010;
const double pi = acos(-1.0);
struct node
{
    double x, y;
};
std::string s1, s2;
node a[MaxN], b[MaxN];
int  l, r[MaxN], ans[MaxN], lena, lenb, lim = 1;
node operator * (node x, node y)
{
    return (node){x.x * y.x - x.y * y.y, x.x * y.y + x.y * y.x};
}
node operator + (node x, node y)
{
    return (node){x.x + y.x, x.y + y.y};
}
node operator - (node x, node y)
{
    return (node){x.x - y.x, x.y - y.y};
}

void FFT(node *x, double flag)
{
    for(int i = 0; i < lim; i++)
        if(i < r[i])
            std::swap(x[i], x[r[i]]);
    for(int j = 1; j < lim; j <<= 1)
    {
        node T = (node){cos(pi / j), flag * sin(pi / j)};
        for(int k = 0; k < lim; k += (j << 1))
        {
            node t = (node){1, 0};
            for(int l = 0; l < j; l++, t = t * T)
            {
                node nx = x[k + l], ny = t * x[k + j + l];
                x[k + l] = nx + ny;
                x[k + j + l] = nx - ny;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    std::cin >> s1 >> s2;
    for(int i = n - 1; i >= 0; i--)
        a[lena++].x = s1[i] - '0', b[lenb++].x = s2[i] - '0';
    while(lim < n + n)
        lim <<= 1, l++;
    for (int i = 0; i <= lim; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    FFT(a, 1), FFT(b, 1);
    for(int i = 0; i <= lim; i++)
        a[i] = a[i] * b[i];
    FFT(a, -1);
    for(int i = 0; i <= lim; i++)
    {
        ans[i] += (int)(a[i].x / lim + 0.5);
        if(ans[i] >= 10)
            ans[i + 1] += ans[i] / 10, ans[i] %= 10, lim += (i == lim);
    }
    while(!ans[lim] && lim >= 1)
        --lim;
    ++lim;
    while(--lim >= 0)
        printf("%d", ans[lim]);
    return 0;
}