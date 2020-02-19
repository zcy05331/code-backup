int t;
cin >> t;
while (t--)
{
    string str;
    ve<int> s[27];
    cin >> str;
    for (int i = 0; i < str.size(); i++)
        s[str[i] - 'a'].pb(i + 1);
    cin >> str;
    int ans = 0, now = 0, flg = 0;
    for (int i = 0; i < str.size(); i++)
        if (s[str[i] - 'a'].empty())
            flg = 1;
    if (flg)
    {
        cout << -1 << '\n';
        continue;
    }
    for (int i = 0; i < str.size(); i++)
    {
        auto it = lower_bound(s[str[i] - 'a'].begin(), s[str[i] - 'a'].end(), now + 1);
        if (it == s[str[i] - 'a'].end())
            ans++, it = lower_bound(s[str[i] - 'a'].begin(), s[str[i] - 'a'].end(), 1);
        now = *it;
    }
    ans++;
    cout << ans << '\n';
}
