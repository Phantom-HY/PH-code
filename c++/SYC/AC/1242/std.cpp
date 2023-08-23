#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
struct tree
{
    int data;
    int l, r;
    int fa;
} a[105];
int cnt = 0;
void InTree(int x)
{
    if (x == 0)
        return;
    InTree(a[x].l);
    cnt++;
    if (a[x].data == k)
        printf("%d", cnt), exit(0);
    InTree(a[x].r);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[i] = {x, y, z};
        a[y].fa = a[z].fa = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i].fa == 0)
            InTree(i);
    }
    return 0;
}