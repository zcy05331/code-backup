#include <bits/stdc++.h>
#define mp(i, j) std::make_pair(i, j)
#define p std::pair<int, int>
p a[4];
std::map<p, int> m1, m2, m3, m4;
void add1()
{
    for (int i = a[1].first; i <= a[2].first; i++)
        m1[mp(i, a[1].second)] = 1;
    if (a[1].second <= a[2].second)
    {
        for (int i = a[1].second; i <= a[2].second; i++)
            m1[mp(a[2].first, i)] = 1;
    }
    else
    {
        for (int i = a[1].second; i >= a[2].second; i--)
            m1[mp(a[2].first, i)] = 1;
    }
    for (int i = a[2].first; i <= a[3].first; i++)
        m1[mp(i, a[2].second)] = 1;
    if (a[2].second <= a[3].second)
    {
        for (int i = a[2].second; i <= a[3].second; i++)
            m1[mp(a[3].first, i)] = 1;
    }
    else
    {
        for (int i = a[2].second; i >= a[3].second; i--)
            m1[mp(a[3].first, i)] = 1;
    }
}
void add2()
{
    for (int i = a[1].first; i <= a[2].first; i++)
        m2[mp(i, a[1].second)] = 1;
    if (a[1].second <= a[2].second)
    {
        for (int i = a[1].second; i <= a[2].second; i++)
            m2[mp(a[2].first, i)] = 1;
    }
    else
    {
        for (int i = a[1].second; i >= a[2].second; i--)
            m2[mp(a[2].first, i)] = 1;
    }

    if (a[2].second <= a[3].second)
    {
        for (int i = a[2].second; i <= a[3].second; i++)
            m2[mp(a[2].first, i)] = 1;
    }
    else
    {
        for (int i = a[2].second; i >= a[3].second; i--)
            m2[mp(a[2].first, i)] = 1;
    }
    for (int i = a[2].first; i <= a[3].first; i++)
        m2[mp(i, a[3].second)] = 1;
}
void add3()
{

    if (a[1].second <= a[2].second)
    {
        for (int i = a[1].second; i <= a[2].second; i++)
            m3[mp(a[1].first, i)] = 1;
    }
    else
    {
        for (int i = a[1].second; i >= a[2].second; i--)
            m3[mp(a[1].first, i)] = 1;
    }
    for (int i = a[1].first; i <= a[2].first; i++)
        m3[mp(i, a[2].second)] = 1;
    if (a[2].second <= a[3].second)
    {
        for (int i = a[2].second; i <= a[3].second; i++)
            m3[mp(a[2].first, i)] = 1;
    }
    else
    {
        for (int i = a[2].second; i >= a[3].second; i--)
            m3[mp(a[2].first, i)] = 1;
    }
    for (int i = a[2].first; i <= a[3].first; i++)
        m3[mp(i, a[3].second)] = 1;
}
void add4()
{
    if (a[1].second <= a[2].second)
    {
        for (int i = a[1].second; i <= a[2].second; i++)
            m4[mp(a[1].first, i)] = 1;
    }
    else
    {
        for (int i = a[1].second; i >= a[2].second; i--)
            m4[mp(a[1].first, i)] = 1;
    }
    for (int i = a[1].first; i <= a[2].first; i++)
        m4[mp(i, a[2].second)] = 1;
    for (int i = a[2].first; i <= a[3].first; i++)
        m4[mp(i, a[2].second)] = 1;
    if (a[2].second <= a[3].second)
    {
        for (int i = a[2].second; i <= a[3].second; i++)
            m4[mp(a[3].first, i)] = 1;
    }
    else
    {
        for (int i = a[2].second; i >= a[3].second; i--)
            m4[mp(a[3].first, i)] = 1;
    }
}
inline int print(std::map<p, int> m)
{
    for (std::map<p, int>::iterator it = m.begin(); it != m.end(); it++)
        printf("%d %d\n", it->first.first, it->first.second);
}
int main()
{
    int cnt = 0;
    for (int i = 1; i <= 3; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    std::sort(a + 1, a + 3 + 1);
    add1(), add2(), add3(), add4();
    cnt = std::min(std::min(m1.size(), m2.size()), std::min(m3.size(), m4.size()));
    printf("%d\n", cnt);
    if (m1.size() == cnt)
        return 0 * print(m1);
    if (m2.size() == cnt)
        return 0 * print(m2);
    if (m3.size() == cnt)
        return 0 * print(m3);
    if (m4.size() == cnt)
        return 0 * print(m4);
    return 0;
}