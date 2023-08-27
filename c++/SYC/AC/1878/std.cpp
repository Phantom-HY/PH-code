#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int d[105];
vector<int> g[105];
queue<int> q;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        while (scanf("%d", &x) && x != 0)
            g[i].push_back(x), d[x]++;
    }
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        printf("%d ", u);
        for (int i = 0; i < g[u].size(); i++)
        {
            d[g[u][i]]--;
            if (d[g[u][i]] == 0)
                q.push(g[u][i]);
        }
    }
    return 0;
}