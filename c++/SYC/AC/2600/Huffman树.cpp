#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x;
ll ans;
priority_queue<ll, vector<ll>, greater<ll>> a;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &x), a.push(x);
    while (a.size() != 1)
    {
        ll x, y;
        x = a.top();
        a.pop();
        y = a.top();
        a.pop();
        a.push(x + y);
        ans+=x+y;
    }
    printf("%lld\n", ans);
    return 0;
}