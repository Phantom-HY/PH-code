#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, T;
void fun(ll n)
{
    if (n == 0)
    {
        printf("-1");
        return;
    }
    string ans = "";
    while (n != 0)
    {
        if (n % 3 == 2)
        {
            printf("-1");
            return;
        }
        ans += n % 3 + '0', n /= 3;
    }
    for (ll i = 0, m = 1; i < ans.size(); i++, m *= 3)
    {
        if (ans[i] != '0')
            printf("%lld ", m);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld", &n);
        fun(n);
        puts("");
    }
    return 0;
}