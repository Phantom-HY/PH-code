#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, t;
ll ans;
stack<int> a;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        while (!a.empty() && a.top() <= t)
            a.pop();
        ans += a.size();
        a.push(t);
    }
    printf("%lld", ans);
    return 0;
}