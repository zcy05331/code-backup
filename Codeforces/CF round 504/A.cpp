#include <bits/stdc++.h>
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if(n > m + 1)
    {
        printf("NO");
        return 0;
    }
    std::string s, t;
    std::cin >> s >> t;
    int match = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            match = i;
            break;
        }
    }
    if(match == n)
    {
        if(s == t)printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    std::string s1 = s.substr(0 ,match), s2 = s.substr(match + 1, n);  
    std::string t1 = t.substr(0, match), t2 = t.substr(m - s2.length(), s2.length());
    //std::cout << t1 << " " << t2 << std::endl;
    if( t1 == s1 && t2 == s2 && int(s1.length() + s2.length()) <= m)printf("YES");
    else printf("NO");
    return 0;
}