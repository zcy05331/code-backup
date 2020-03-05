int t;
in >> t;
auto solve = [&]() {
    int n;
    string s;
    in >> n;
    in >> s;
    for (int i = 1; i <= n; i++)
    {
        string tmp = "";
        int id = i;
        int fi = (n - i) % 2 == 1 ? 0 : i - 1;
        for (int j = 0; j < n; j++)
        {
            if (j + i - 1 >= n)
            {
                if ((n - i) % 2 == 1)
                    tmp += s[fi], fi++;
                else
                    --fi, tmp += s[fi];
            }
            else
            {
                tmp += s[j + i - 1];
            }
        }
        a[i] = {tmp, id};
    }
    sort(a + 1, a + n + 1);
};
while (t--)
{
    solve();
    out << a[1].fir << '\n'
        << a[1].sec << '\n';
}
