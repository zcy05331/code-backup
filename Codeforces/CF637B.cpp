# include <bits/stdc++.h>

std::map<std::string, int> m;

std::vector<std::pair<int, std::string> > vec;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        std::string s;
        std::cin >> s;
        m[s] = i;
    }
    for(std::map<std::string, int>::iterator it = m.begin(); it != m.end(); it++)
        vec.push_back(std::make_pair(it->second, it->first));
    std::sort(vec.begin(), vec.end());
    for(int i = vec.size() - 1; i >= 0; i--)
        std::cout << vec[i].second << "\n";
    return 0;
}