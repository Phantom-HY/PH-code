#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[80005];
stack<int> q;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && a[i] >= q.top())
            q.pop();
        ans += q.size();
        q.push(a[i]);
    }
    printf("%lld", ans);
    return 0;
}