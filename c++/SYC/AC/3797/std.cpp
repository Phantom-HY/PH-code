#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll op, x;
ll cnt = 1;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld\n", &n);
    for (ll i = 1; i <= n; i++)
    {
        ll num;
        scanf("%c%lld ", &op, &x);
        if (op == '+')
            num = cnt + x;
        else if (op == '-')
            num = cnt - x;
        else if (op == '*')
            num = cnt * x;
        else
            num = ceil(cnt * 1.0 / x);
        scanf("%c%lld\n", &op, &x);
        if (op == '+')
            num = max(num, cnt + x);
        else if (op == '-')
            num = max(num, cnt - x);
        else if (op == '*')
            num = max(num, cnt * x);
        else
            num = max(num, ll(ceil(cnt * 1.0 / x)));
        cnt = num;
        if (cnt < 1)
            printf("No\n%lld", i - 1), exit(0);
    }
    printf("Yes\n%lld", cnt);
    return 0;
}