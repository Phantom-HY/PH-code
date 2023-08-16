#include <iostream>
#include <cstdio>
using namespace std;
char c, a;
int f = 1, now = 1, k, b, x;
bool r;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while (cin >> c)
    {
        if (c == '-')
        {
            b += now * f * x;
            x = 0;
            f = -1;
            r = 0;
            continue;
        }
        if (c == '+')
        {
            b += now * f * x;
            x = 0;
            f = 1;
            r = 0;
            continue;
        }
        if (c == '=')
        {
            b += now * f * x;
            x = 0;
            f = 1;
            now = -1;
            r = 0;
            continue;
        }
        if (c >= 'a' && c <= 'z')
        {
            if (r)
            {
                k += now * f * x;
                x = 0;
            }
            else
                k += now * f;
            a = c;
            r = 0;
            continue;
        }
        x = x * 10 + c - '0';
        r = 1;
    }
    b += now * f * x;
    double ans = double(-b * 1.0 / k);
    if (ans == -0.0)
        ans = 0;
    printf("%c=%.3lf", a, ans);
    return 0;
}