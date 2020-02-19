# include <bits/stdc++.h>
std::map<char, int> m1, m2;
int main()
{
    std::string s[6], str;
    std::cin >> str;
    for(int i = 1; i <= 5; i++)
        std::cin >> s[i], m1[s[i][0]] = 1, m2[s[i][1]] = 1;
    if(m1[str[0]] || m2[str[1]])
        return printf("YES\n") * 0;
    printf("NO\n");
    return 0;
}