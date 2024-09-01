#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<int, int> a[1000005];
stack<pair<int, int>> q;
int ans[1000005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].first), a[i].second = i;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && q.top().first < a[i].first)
        {
            ans[q.top().second] = i;
            q.pop();
        }
        q.push(a[i]);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}