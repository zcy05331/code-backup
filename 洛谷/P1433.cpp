// luogu-judger-enable-o2
#include <bits/stdc++.h>
const int MaxN = 20;
struct node
{
    int x, y, w;
};
int n;
node a[MaxN];
double ans = 1e18, t;
int used[MaxN], temp[MaxN];
inline int read()
{
    bool f = 0;
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = true;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    return (!f) ? x : -x;
}
double calc()
{
    double tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp += 1.0 * sqrt(1.0 * (a[temp[i]].x - a[temp[i - 1]].x) * (a[temp[i]].x - a[temp[i - 1]].x) + 1.0 * (a[temp[i]].y - a[temp[i - 1]].y) * (a[temp[i]].y - a[temp[i - 1]].y));
    }
    return tmp;
}
void sa()
{
    for(int i = 1; i <= 500000; i++)
    {
        memcpy(temp, used, sizeof(temp));
        int x = rand() % n + 1, y = rand() % n + 1;
        std::swap(temp[x], temp[y]);
        double tmp = calc();
        if (tmp - ans < 0)
            memcpy(used, temp, sizeof(used)), ans = tmp;
    }
}
int main()
{
    n = read();
    srand(time(NULL));
    for (int i = 1; i <= n; i++)
        a[i].x = read(), a[i].y = read(), used[i] = i;
    sa();
    printf("%.2lf", ans);
    return 0;
}
