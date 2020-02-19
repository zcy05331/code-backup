#include <bits/stdc++.h>

struct node
{
    int a, b, id;
};
std::vector<node> a, b;

int cmp1(node a, node b) { return a.b > b.b || (a.b == b.b && a.a > b.a); }

int cmp2(node a, node b) { return a.b < b.b || (a.b == b.b && a.a < b.a); }

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < y)
            a.push_back((node){x, y, i});
        else
            b.push_back((node){x, y, i});
    }
    sort(a.begin(), a.end(), cmp1);
    sort(b.begin(), b.end(), cmp2);
    if (a.size() > b.size())
    {
        printf("%d\n", a.size());
        for (int i = 0; i < a.size(); i++)
            printf("%d ", a[i].id);
    }
    else
    {
        printf("%d\n", b.size());
        for (int i = 0; i < b.size(); i++)
            printf("%d ", b[i].id);
    }
    puts("");
    return 0;
}