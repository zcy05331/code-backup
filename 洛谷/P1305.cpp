#include <bits/stdc++.h>
struct node
{
    char ch;
    int l, r;
};
node a[50];
int n, val[27];
std::string s[50];
inline void dfs(int x)
{
    printf("%c", a[x].ch);
    if(a[x].l)
        dfs(a[x].l);
    if(a[x].r)
        dfs(a[x].r);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        std::cin >> s[i], val[s[i][0] - 'a' + 1] = i;
    for (int i = 1; i <= n; i++)
    {
        a[i].ch = s[i][0];
        if (s[i][1] != '*')
            a[i].l = val[s[i][1] - 'a' + 1];
        if (s[i][2] != '*')
            a[i].r = val[s[i][2] - 'a' + 1];
    }
    dfs(1);
    return 0;
}
