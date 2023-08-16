#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct Tree
{
    char data[25];
    int fa;
    int l, r;
} a[25];
void dfs(int x,int dep)
{
    if (x == -1)
        return;
    if ((a[x].l != -1 || a[x].r != -1)&&dep!=0)
        printf("(");
    dfs(a[x].l,dep+1);
    printf("%s", a[x].data);
    dfs(a[x].r,dep+1);
    if ((a[x].l != -1 || a[x].r != -1)&&dep!=0)
        printf(")");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s %d %d\n", &a[i].data, &a[i].l, &a[i].r);
        if (a[i].l != -1)
            a[a[i].l].fa = i;
        if (a[i].r != -1)
            a[a[i].r].fa = i;
    }
    for (int i = 1; i <= n; i++)
        if (a[i].fa == 0)
            dfs(i,0);
    return 0;
}