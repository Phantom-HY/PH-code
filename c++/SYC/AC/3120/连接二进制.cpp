#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, cnt = 1, sx = 1, cs = 0, ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        ans = (ans << cnt) + i;
        ans %= 1000000007;
        cs++;
        if (cs == sx)
        {
            sx *= 2;
            cnt++;
            cs = 0;
        }
    }
    printf("%lld", ans);
    return 0;
}