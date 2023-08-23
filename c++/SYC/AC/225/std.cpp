#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, len;
char a[100005];
struct Tree
{
    char data;
    Tree *l = NULL, *r = NULL;
};
char fun(int l, int r)
{
    bool flagB = 0, flagI = 0;
    for (int i = l; i <= r; i++)
    {
        flagB = flagB || (a[i] == 'B');
        flagI = flagI || (a[i] == 'I');
    }
    if (flagB && flagI)
        return 'F';
    if (flagB)
        return 'B';
    return 'I';
}
void Get_PostTree(Tree *root)
{
    if (root == NULL)
        return;
    Get_PostTree(root->l);
    Get_PostTree(root->r);
    cout << root->data;
}
void dfs(Tree *root, int l, int r)
{
    root->data = fun(l, r);
    if (l == r)
        return;
    root->l = new Tree;
    root->r = new Tree;
    int mid = (l + r) / 2;
    dfs(root->l, l, mid);
    dfs(root->r, mid + 1, r);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    int len = 1 << n;
    scanf("%s", a + 1);
    Tree *root = new Tree;
    dfs(root, 1, len);
    Get_PostTree(root);
    return 0;
}