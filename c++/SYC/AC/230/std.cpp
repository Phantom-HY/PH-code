#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll a[200005], b[200005];
struct node
{
    int l, r;
    ll sum;
    bool operator<(const node &x) const
    {
        return sum > x.sum;
    }
};
priority_queue<node> q;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    q.push({1, 1, a[1] + b[1]});
    for (int i = 1; i < k; i++)
    {
        auto w = q.top();
        q.pop();
        if (w.r == 1)
            q.push({w.l + 1, w.r, a[w.l + 1] + b[w.r]});
        q.push({w.l, w.r + 1, a[w.l] + b[w.r + 1]});
    }
    printf("%lld\n", q.top().sum);
    return 0;
}