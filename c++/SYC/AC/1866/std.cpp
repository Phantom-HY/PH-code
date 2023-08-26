#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct Tree
{
    int fa;
    int l, r;
    int dep;
} a[100005];
int cnt[100005];
int ans_dep, ans_cnt;
void fun(int x)
{
    cnt[a[x].dep]++;
    // printf("%d %d %d\n", a[x].dep, a[x].l, a[x].r);
    ans_cnt = max(ans_cnt, cnt[a[x].dep]);
    ans_dep = max(ans_dep, a[x].dep);
    if (a[x].l != 0)
        a[a[x].l].dep = a[x].dep + 1, fun(a[x].l);
    if (a[x].r != 0)
        a[a[x].r].dep = a[x].dep + 1, fun(a[x].r);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        scanf("%d%d", &a[x].l, &a[x].r);
        a[a[x].l].fa = x;
        a[a[x].r].fa = x;
    }
    for (int i = 1; i <= n; i++)
        if (a[i].fa == 0)
        {
            a[i].dep = 1, fun(i);
            break;
        }
    printf("%d %d\n", ans_dep, ans_cnt);
    return 0;
}