#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, k, m, a, b;
ll ans;
unordered_map<ll, bool> vis;
void fun(ll x, ll step)
{
    if (step >= ans)
        return;
    if (x % m == 0)
    {
        ans = step;
        return;
    }
    for (int i = 0; i < k; i++)
        fun(x * k + i, step + a);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld%lld%lld%lld", &n, &k, &m, &a, &b);
        ans = 0;
        if (n % m == 0)
        {
            printf("0\n");
            continue;
        }
        if (k == 1)
        {
            printf("-1\n");
            continue;
        }
        ll i = n;
        while (i)
        {
            i /= k;
            ans += b;
        }
        ll sum = 0;
        i = n;
        while (i)
        {
            fun(i, sum);
            sum += b;
            i /= k;
        }
        printf("%lld\n", ans);
    }
    return 0;
}