# include <bits/stdc++.h>
std::string a, b;
inline void solve(std::string a, std::string b)
{
    if(a.size() > 0)
    {
        printf("%c", b[b.size() - 1]);
        int k = a.find(b[b.size() - 1]);
        solve(a.substr(0, k) , b.substr(0 ,k));
        solve(a.substr(k + 1), b.substr(k, a.size() - k - 1));
    }
}
int main()
{
    std::cin >> a >> b;
    solve(a, b);
    return 0;
}
