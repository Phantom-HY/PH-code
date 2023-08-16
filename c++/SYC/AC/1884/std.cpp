#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w,net;
} e[1000005];
int n, m, head[100005], pos, u, v,w;
void addEdge(int u, int v,int w)
{
    e[++pos] = {u, v, w,head[u]};
    head[u] = pos;
}
bool vis[100005];
int dis[100005];
void SPFA(int s)
{
    memset(vis, false, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = e[i].net)
        {
            int v = e[i].v, w = e[i].w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                    vis[v] = true, q.push(v);
            }
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    SPFA(1);
    printf("%d\n", dis[n]);
    return 0;
}