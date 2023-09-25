#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
pair<ll, ll> a[200005];
struct cmp
{
    bool operator()(pair<ll, ll> &a, pair<ll, ll> &b)
    {
        return a.second < b.second;
    }
};
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> q;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld%lld", &a[i].first, &a[i].second);
    sort(a + 1, a + n + 1);
    ll sum = a[n].first;
    ll i = n;
    ll ans = 0;
    while (i != 0)
    {
        while (a[i].first == sum && i != 0)
            q.push(a[i]), i--;
        while (sum != a[i].first && q.size() != 0)
            sum--, ans += q.top().second, q.pop();
        sum = a[i].first;
    }
    printf("%lld\n", ans);
    return 0;
}