#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, t;
set<int> x[100005], y;
int a[100005], len[100005];
vector<int> s[100005];
bool vis[100005];
void bfs()
{
    queue<int> q;
    q.push(1);
    int dep = 0;
    vis[1] = 1;
    while (!q.empty())
    {
        dep++;
        len[dep] = q.size();
        for (int i = 1; i <= len[dep]; i++)
        {
            int c = q.front();
            q.pop();
            x[dep].insert(c);
            for (auto &&j : s[c])
                if (!vis[j])
                    vis[j] = 1, q.push(j);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &t);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        s[u].push_back(v);
        s[v].push_back(u);
    }
    bfs();
    while (t--)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        bool flag = 1;
        for (int le = len[1], j = 1, st = 1; le; le = len[++j])
        {
            y.clear();
            for (int h = st; st < h + le; st++)
                y.insert(a[st]);
            if (y != x[j])
            {
                flag = 0;
                break;
            }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}