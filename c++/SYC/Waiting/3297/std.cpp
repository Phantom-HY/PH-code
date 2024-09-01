#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100005];
ll ans = 0;
void fun(ll x,ll y,int i)
{
    if (i == n + 1)
    {
        ans += x * y;
        return;
    }
    fun(x ^ a[i], y, i + 1);
    fun(x, y ^ a[i], i + 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    fun(0, 0, 1);
    printf("%lld", ans);
    return 0;
}