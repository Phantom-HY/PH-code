#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
ll n, m, x, y, ans[1005];
char t[15];
stack<pair<ll, ll>> q;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s%lld%lld", t, &x, &y);
        if (t[0] == 's')
        {
            if (q.size())
                ans[q.top().x] += y - q.top().y;
            q.push({x, y});
        }
        else
        {
            auto f=q.top();
            q.pop();
            ans[f.x]+=y-f.y+1;
            if (q.size())
                q.top().y = y + 1;
        }
    }
    for (int i=1;i<=n;i++)
        printf("%lld\n",ans[i]);
    return 0;
}