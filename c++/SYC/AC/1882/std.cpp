#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int u, v;
int ans;
struct tree
{
    int fa;
    int dep;
    vector<int> child;
} a[1000005];
void fun(int x)
{
    ans = max(ans, a[x].dep);
    if (a[x].child.size() == 0)
        return;
    for (auto &&i : a[x].child)
        a[i].dep = a[x].dep + 1, fun(i);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        a[u].child.push_back(v);
        a[v].fa = u;
    }
    for (int i = 1; i <= n; i++)
        if (a[i].fa == 0)
        {
            fun(i);
        }
    printf("%d\n", ans);
    return 0;
}