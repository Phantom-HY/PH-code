#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w, net;
} e[200005];
int n, m, head[100005], pos, u, v, w;
void addEdge(int u, int v, int w)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
int s,d;
int a[105];
bool vis[100005];
ll dis[100005];
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
    scanf("%d%d%d%d",&n,&m,&s,&d);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    for (int i=1;i<=s;i++)
    {
        scanf("%d",&u);
        addEdge(0, u, 0);
    }
    for (int i=1;i<=d;i++)
    {
        scanf("%d",a+i);
    }
    SPFA(0);
    ll ans=1e18;
    for (int i=1;i<=d;i++)
    {
        ans=min(ans,dis[a[i]]);
    }
    printf("%lld",ans);
    return 0;
}