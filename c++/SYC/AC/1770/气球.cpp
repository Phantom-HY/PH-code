#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int x, h;
    bool operator<(const node t) const
    {
        if (h != t.h)
            return h > t.h;
        return x < t.x;
    }
} a[100005];
bool vis[100005];
int n, ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].x, &a[i].h);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        //printf("%d %d\n",a[i].x,a[i].h);
        if (!vis[i])
        {
            ans++;
            vis[i] = 1;
            int X = a[i].x, H = a[i].h - 1;
            for (int j = i + 1; j <= n; j++)
                if (!vis[j] && a[j].h == H && a[j].x > X)
                    vis[j] = 1, H--, X = a[j].x;
                else if (a[j].h < H)
                    break;
        }
    }
    printf("%d",ans);
    return 0;
}