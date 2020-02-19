# include <bits/stdc++.h>

int cnt[26];

int main()
{
    int n;
    scanf("%d", &n);
    std::string s;
    std::cin >> s;
    int len = s.length();
    std::sort(s.begin(), s.end());
    std::cout << s;
    return 0;
}