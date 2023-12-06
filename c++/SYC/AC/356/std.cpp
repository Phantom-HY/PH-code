#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<30005> ans[30005];
struct Edge
{
    int u, v, net;
} e[30005];
int n, m, head[30005], pos, u, v;
void addEdge(int u, int v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
int d[30005];
vector<int> sum;
void TopoSort()
{
    // priority_queue<int, vector<int>, greater<int>> q;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        // int u = q.top();
        int u = q.front();
        q.pop();
        sum.push_back(u);
        // printf("%d ", u);
        for (int i = head[u]; i; i = e[i].net)
        {
            int v = e[i].v;
            d[v]--;
            if (d[v] == 0)
                q.push(v);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        d[v]++;
    }
    TopoSort();
    reverse(sum.begin(), sum.end());
    for (auto &&i:sum)
    {
        ans[i][i]=1;
        for (int j = head[i]; j; j = e[j].net)
            ans[i] |= ans[e[j].v];
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i].count());
    return 0;
}