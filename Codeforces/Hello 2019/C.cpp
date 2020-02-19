#include <bits/stdc++.h>

const int MaxN = 100010, MaxM = 500010;

std::string s[MaxN], str[MaxN];
std::map<std::string, int> m;

inline std::string change(std::string s)
{
    int len = s.length();
    std::string tmp = "";
    for (int i = 0; i < len; i++)
        tmp += ((s[i] == '(') ? ')' : '(');
    return tmp;
}

inline int check1(std::string s)
{
    std::stack<char> st;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')' && st.empty())
            return 0;
        else
            st.pop();
    }
    return 1;
}

inline void check(int x, std::string s)
{
    std::vector<char> st;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (st.empty())
        {
            st.push_back(s[i]);
            continue;
        }
        if (s[i] == '(')
            st.push_back('(');
        else if (s[i] == ')' && st.back() == '(')
            st.pop_back();
        else if (s[i] == ')' && st.back() == ')')
            st.push_back(')');
    }
    std::string tmp = "";
    for (int i = 0; i < st.size(); i++)
        tmp += ((st[i] == '(') ? ')' : '(');
    if (check1(tmp + s) || check1(s + tmp))
        ++m[tmp];
    //  std::cout << " " << s << " " << tmp << "\n";
}

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        std::cin >> s[i], check(i, s[i]);
    for (std::map<std::string, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if (it->first == "")
            continue;
        ans += std::min(it->second, m[change(it->first)]);
    }
    printf("%d\n", (ans / 2) + (m[""] / 2));
    return 0;
}