#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<int, vector<int>, greater<int>> a;
ll n, ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &n);
    for (int i = 1, x; i <= n; i++)
        scanf("%d", &x), a.push(x);
    for (int i = 1; i < n; i++)
    {
        int x = a.top();
        a.pop();
        int y = a.top();
        a.pop();
        a.push(x + y);
        ans += x + y;
    }
    printf("%lld", ans);
    return 0;
}