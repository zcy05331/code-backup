#include <bits/stdc++.h>

std::stack<int> st;
char s[100010];

int div2(int x, int y)
{
    return x / y;
}

int main()
{

    scanf("%s", s);
    int len = strlen(s);
    int tmp = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] <= '9' && s[i] >= '0')
        {
            tmp = tmp * 10 + s[i] - '0';
        }
        else
        {
            int x = 0, y = 0;
            if (tmp)
                st.push(tmp);
            tmp = 0;
            if (s[i] == '@')
                break;
            if (s[i] == '.')
                continue;
            if (!st.empty())
            {
                x = st.top();
                st.pop();
            }
            if (!st.empty())
            {
                y = st.top();
                st.pop();
            }
            if (s[i] == '+')
            {
                st.push(y + x);
            }
            else if (s[i] == '-')
            {
                st.push(y - x);
            }
            else if (s[i] == '*')
            {
                st.push(y * x);
            }
            else if (s[i] == '/')
            {
                st.push(div2(y, x));
            }
        }
    }
    printf("%d", st.top());
    return 0;
}
