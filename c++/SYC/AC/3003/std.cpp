#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int net[200005], pre[200005];
int n, m;
int sum[200005];
int ans;
bool vis[200005];
struct node
{
    int val, id;
    bool operator<(node it) const
    {
        return val < it.val;
    }
};
void del(int x)
{
    pre[x] = pre[pre[x]];
    net[x] = net[net[x]];
    net[pre[x]] = x;
    pre[net[x]] = x;
}
priority_queue<node> q;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    if (m > n / 2)
        printf("Error!"), exit(0);
    for (int i = 1; i < n; i++)
        net[i] = i + 1;
    net[n] = 1;
    for (int i = 2; i <= n; i++)
        pre[i] = i - 1;
    pre[1] = n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &sum[i]), q.push({sum[i], i});
    for (int i = 1; i <= m; i++)
    {
        while (vis[q.top().id])
            q.pop();
        auto f = q.top();
        q.pop();
        ans += f.val;
        vis[pre[f.id]] = vis[net[f.id]] = 1;
        sum[f.id] = sum[pre[f.id]] + sum[net[f.id]] - sum[f.id];
        q.push({sum[f.id], f.id});
        del(f.id);
    }
    printf("%d\n", ans);
    return 0;
}