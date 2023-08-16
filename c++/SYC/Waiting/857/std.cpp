#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
struct Edge
{
    char u, v;
    int net;
} e[100005];
int n, m, head[100005], pos;
void addEdge(char u, char v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
int d[100005];
int len;
char ans[100005];
int id;
char x[35][35];
int vis[35][35];
bool visd[35];
void TopoSort()
{
    priority_queue<char> q;
    len = 0;
    // queue<int> q
    for (int i = 'A'; i <= 'Z'; i++)
        if (d[i] == 0 && visd[i-'A'])
        q.push(i);
    while (!q.empty())
    {
        auto u = q.top();
        q.pop();
        ans[++len] = u;
        // printf("%d ", u);
        for (int i = head[u]; i; i = e[i].net)
        {
            auto v = e[i].v;
            d[v]--;
            if (d[v] == 0)
                q.push(v);
        }
    }
    for (int i = 'A'; i <= 'Z'; i++)
        if (d[i] != 0)
        {
            printf("Case #%d: -1\n", id);
            return;
        }
    printf("Case #%d: ", id);
    for (int i = 1; i <= len; i++)
        printf("%c", ans[i]);
    puts("");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d\n", &t);
    while (t--)
    {
        id++;
        pos = 0;
        memset(head, 0, sizeof head);
        memset(d, 0, sizeof d);
        memset(vis, 0, sizeof vis);
        memset(visd, 0, sizeof visd);
        scanf("%d%d\n", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%s", x[i] + 1);
        for (int i = 1; i < n; i++)
            for (int j = 1; j <= m; visd[x[i][j] - 'A'] = visd[x[i + 1][j] - 'A'] = 1, j++)
                if (x[i][j] != x[i + 1][j])
                    if (!vis[x[i][j] - 'A'][x[i + 1][j] - 'A'])
                        addEdge(x[i + 1][j], x[i][j]), d[x[i][j]]++,
                            vis[x[i][j] - 'A'][x[i + 1][j] - 'A'] = 1;
        TopoSort();
    }
    return 0;
}