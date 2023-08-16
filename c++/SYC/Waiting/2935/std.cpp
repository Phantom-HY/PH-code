#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w, net;
} e[100005];
int n, m, head[100005], pos, u, v, w;
void addEdge(int u, int v, int w)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
int a[100005],b[100005];
int fx_4[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int ans;
void fun()
{
    
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int y=0;y<4;y++)
            {
                int tx,ty;
                tx=i+fx_4[y][0];
                ty=j+fx_4[y][1];
                if (tx>0&&tx<=n&&ty>0&&ty<=m)
                    addEdge(i*n+j,tx*n+j,i!=tx?a[min(tx,i)]:a[min(ty,j)]);
            }
    return 0;
}