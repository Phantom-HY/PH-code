#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int fa;
    int v; // 热情度
} a[20005];
int n, m, x, v;
queue<int> s;
int e[20005], o[20005];
void bfs()
{
    while (!s.empty())
    {
        int len = s.size();
        // printf("st:len=%d\n",len);
        if (len==1)
        {
            printf("%d",a[s.front()].v);
            exit(0);
        }
        memset(e, 0, sizeof e);
        memset(o, 0, sizeof o);
        for (int i = 0; i < len; i++)
        {
            int x = s.front();
            s.pop();
            // printf("-%d\n",x);
            if (e[a[x].fa] != 0)
                e[a[x].fa] = max(e[a[x].fa], a[x].v) - min(e[a[x].fa], a[x].v);
            else
                e[a[x].fa] = a[x].v, o[i] = a[x].fa;
            // printf("%d to %d\n",a[x].v,a[x].fa);
            a[x].v = 0;
        }
        for (int i=0;i<len;i++)
            if (o[i]!=0)
            {
                a[o[i]].v=e[o[i]];
                s.push(o[i]);
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
    a[1].fa=1;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l != 0)
            a[l].fa=i;
        if (r != 0)
            a[r].fa=i;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &v);
        a[x].v = v;
        s.push(x);
    }
    bfs();
    printf("%d",a[1].v);
    return 0;
}