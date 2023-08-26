#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct Tree
{
    int data;
    int l, r;
} a[105];
void Get_PreTree(int root)
{
    if (root == 0)
        return;
    printf("%d ", a[root].data);
    Get_PreTree(a[root].l);
    Get_PreTree(a[root].r);
}
void Get_InTree(int root)
{
    if (root == 0)
        return;
    Get_InTree(a[root].l);
    printf("%d ", a[root].data);
    Get_InTree(a[root].r);
}
void Get_PostTree(int root)
{
    if (root == 0)
        return;
    Get_PostTree(a[root].l);
    Get_PostTree(a[root].r);
    printf("%d ", a[root].data);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i].data, &a[i].l, &a[i].r);
    Get_PreTree(1);
    puts("");
    Get_InTree(1);
    puts("");
    Get_PostTree(1);
    return 0;
}