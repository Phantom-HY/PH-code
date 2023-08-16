#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bao
{
    int w, v;
} a[1005];
bool cmp(bao a, bao b)
{
    return a.v > b.v;
}
int n, m, ans;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].w, &a[i].v);
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (m > a[i].w)
            ans += a[i].w * a[i].v, m -= a[i].w;
        else
        {
            ans += a[i].v * m;
            break;
        }
    }
    printf("%d",ans);
    return 0;
}