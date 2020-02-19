#include <bits/stdc++.h>
std::stack<int> st;
std::vector<int>ans;
int main()
{
    int n, k;
    std::string s;
    scanf("%d%d", &n, &k); 
    std::cin >> s;
    if(n == k)
    {
        std::cout << s;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')st.push(i);
        else if(s[i] == ')')ans.push_back(st.top()), ans.push_back(i), st.pop();
        if(ans.size() == k)break; 
    }
    std::sort(ans.begin(), ans.end());
    for(int i = 0; i < k; i++)
        printf("%c", s[ans[i]]);
    return 0;
}