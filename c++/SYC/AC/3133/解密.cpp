#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;
ll n, d, e, m;
ll fun(ll l, ll r)
{
    if (l > r)
        return -1;
    ll mid = (l + r) >> 1;
    ll q = m - mid;
    if (mid * q < n)
        return fun(mid + 1, r);
    else if (mid * q > n)
        return fun(l, mid - 1);
    return mid;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &k);
    while (k--)
    {
        scanf("%lld%lld%lld", &n, &d, &e);
        m = n - e * d + 2;
        ll k = fun(1, m / 2);
        if (k == -1)
            printf("NO\n");
        else
            printf("%lld %lld\n", k, m - k);
    }
    return 0;
}