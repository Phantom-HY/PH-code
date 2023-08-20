#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Q;
int n;
bool vis[5000005];
int ans[5000005];
queue<int> q;
int bfs(int x)
{
    if (vis[x])
        return ans[x];
    while (!q.empty())
    {
        auto c = q.front();
        q.pop();
        // printf("-%d\n", c);
        if (!vis[c * 2] && c * 2 <= 1e6)
            q.push(c * 2),
                ans[c * 2] = ans[c] + 1,
                        vis[c * 2] = 1;
        if (!vis[c + 1] && c + 1 <= 1e6)
            q.push(c + 1),
                ans[c + 1] = ans[c] + 1,
                        vis[c + 1] = 1;
        if (!vis[c - 1] && c - 1 >= 0)
            q.push(c - 1),
                ans[c - 1] = ans[c] + 1,
                        vis[c - 1] = 1;
        if (c == x)
            return ans[x];
    }
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    q.push(0);
    ans[0] = 0, vis[0] = 1;
    scanf("%d", &Q);
    while (Q--)
    {
        scanf("%d", &n);
        printf("%d\n", bfs(abs(n)));
    }
    return 0;
}