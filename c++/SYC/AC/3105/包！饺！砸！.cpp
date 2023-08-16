#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, ans_n, ans_s, x, y;
int fun(int x)
{
    if (x > 23)
        return 1900 + x;
    else
        return 2000 + x;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        if (y >= ans_s)
        {
            if (y == ans_s)
            {
                if (2023 - fun(x) < 2023 - fun(ans_n))
                    ans_n = x, ans_s = y;
            }
            else
                ans_n = x, ans_s = y;
        }
    }
    printf("%d\n%d", fun(ans_n), ans_s);
    return 0;
}