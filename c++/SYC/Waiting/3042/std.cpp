#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[500005];
int m, l, r;
bool vis[500005];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d%d", &l, &r);
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for(int i = l; i <= r; i++)
            if(!vis[a[i]])
            {
                ans++;
                vis[a[i]] = 1;
            }
        printf("%d\n", ans);
    }
    return 0;
}