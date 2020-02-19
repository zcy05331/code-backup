#include <bits/stdc++.h>
const int MaxN = 20010;
struct point
{
    long double x, y;
    point operator-(point &s)
    {
        return (point){x - s.x, y - s.y};
    }
};
point p[MaxN];
int st[MaxN << 1], top;
double CJ(point a1, point a2, point b1, point b2)
{
    return (a2.x - a1.x) * (b2.y - b1.y) - (b2.x - b1.x) * (a2.y - a1.y);
}
double dis(point p1, point p2)
{
    return sqrt((double)(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
bool cmp(point p1, point p2)
{
    double tmp = CJ(p[1], p1, p[1], p2);
    if (tmp > 0)
        return 1;
    if (tmp == 0 && dis(p[0], p1) < dis(p[0], p2))
        return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        std::cin >> p[i].x >> p[i].y;
    for (int i = 2; i <= n; i++)
        if (p[i].y < p[1].y)
            std::swap(p[i], p[1]);
    std::sort(p + 2, p + n + 1, cmp);
    st[1] = 1;
    top = 1;
    for (int i = 2; i <= n; i++)
    {
        while (top > 1 && CJ(p[st[top - 1]], p[st[top]], p[st[top]], p[i]) <= 0)
            --top;
        st[++top] = i;
    }
    st[top + 1] = 1;
    double ans = 0;
    for (int i = 1; i <= top; i++)
        ans += dis(p[st[i]], p[st[i + 1]]);
    printf("%.2lf\n", ans);
    return 0;
}