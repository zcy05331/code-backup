#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
std::string l, r;
int n, m, a[30], b[30];
std::vector<int> ans[2];
std::queue<int> vec[30][2];
int main()
{
    scanf("%d", &n);
    std::cin >> l >> r;
    for (int i = 0; i < n; i++)
    {
        if (l[i] == '?')
            ++a[0], vec[0][0].push(i+1);
        else
            ++a[l[i] - 'a' + 1], vec[l[i] - 'a' + 1][0].push(i+1);
    }
    for (int i = 0; i < n; i++)
    {
        if (r[i] == '?')
            ++b[0], vec[0][1].push(i+1);
        else
            ++b[r[i] - 'a' + 1], vec[r[i] - 'a' + 1][1].push(i+1);
    }
    m = n;
    for (int i = 1; i <= 26; i++)
    {
        while (a[i] && b[i])
        {
            --a[i], --b[i];
            ans[0].push_back(vec[i][0].front()), vec[i][0].pop();
            ans[1].push_back(vec[i][1].front()), vec[i][1].pop();
        }
    }
    if (a[0])
    {
        for (int i = 1; i <= 26; i++)
        {
            while (b[i] && a[0])
            {
                --a[0], --b[i];
                ans[0].push_back(vec[0][0].front()), vec[0][0].pop();
                ans[1].push_back(vec[i][1].front()), vec[i][1].pop();
            }
        }
    }
    if (b[0])
    {
        for (int i = 1; i <= 26; i++)
        {
            while (b[0] && a[i])
            {
                --a[i], --b[0];
                ans[0].push_back(vec[i][0].front()), vec[i][0].pop();
                ans[1].push_back(vec[0][1].front()), vec[0][1].pop();
            }
        }
    }
    while (a[0] && b[0])
    {
        --a[0], --b[0];
        ans[0].push_back(vec[0][0].front()), vec[0][0].pop();
        ans[1].push_back(vec[0][1].front()), vec[0][1].pop();
    }
    int size = (ans[0].size() + ans[1].size()) / 2;
    printf("%d\n", size);
    for (int i = 0; i < size; i++)
        printf("%d %d\n", ans[0][i], ans[1][i]);
    return 0;
}
