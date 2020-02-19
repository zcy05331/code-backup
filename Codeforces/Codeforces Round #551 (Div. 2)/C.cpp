#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
int n;
std::string s;
std::stack<char> st;
int main()
{
    std::cin >> n >> s;
    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            cnt++;
        else if (s[i] == ')')
            cnt2++;
    }
    if (cnt > n / 2 || cnt2 > n / 2)
        return 0 * puts(":(");
    cnt = n / 2 - cnt, cnt2 = n / 2 - cnt2;
    for (int i = 0; i < n; i++)
    {
        if (cnt && s[i] == '?')
        {
            --cnt, s[i] = '(';
        }
        else if (s[i] == '?')
            cnt2--, s[i] = ')';
    }
    while (st.size())
        st.pop();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push('(');
        else if (st.size() && s[i] == ')')
            st.pop();
        else if (st.size() == 0 && s[i] == ')')
            return 0 * puts(":(");
        if (st.size() == 0 && (i != 0) && (i != n - 1))
            return 0 * puts(":(");
    }
    std::cout << s;
    return 0;
}
