int main()
{
    n = read();
    scanf("%s", s + 1);
    int d = 0;
    for (re int i = 1; i <= n / 2; ++i)
    {
        if (s[i] == '?')
            d += 9;
        else
            d += (s[i] - '0') * 2;
    }
    for (re int i = n / 2 + 1; i <= n; ++i)
    {
        if (s[i] == '?')
            d -= 9;
        else
            d -= (s[i] - '0') * 2;
    }
    puts(d ? "Monocarp" : "Bicarp");
    return 0;
}