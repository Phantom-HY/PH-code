#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct Tree
{
    int data;
    Tree *l, *r;
};
vector<int> in, post; // post后序 in中序
int pos;
// 求后序
Tree *build_PreTree(int l, int r)
{
    if (l > r)
        return NULL;
    Tree *root = new Tree();
    int p = find(in.begin(), in.end(), root->data = post[pos--]) - in.begin();
    root->r = build_PreTree(p + 1, r);
    root->l = build_PreTree(l, p - 1);
    return root;
}
vector<int> ans[35];
int dl;
void Get_PreTree(Tree *root, int dep)
{
    if (root == NULL)
        return;
    dl = max(dep, dl);
    ans[dep].push_back(root->data);
    Get_PreTree(root->l, dep + 1);
    Get_PreTree(root->r, dep + 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++)
        scanf("%d", &x), in.push_back(x);
    for (int i = 0; i < n; i++)
        scanf("%d", &x), post.push_back(x);
    pos = n - 1;
    Tree *root = build_PreTree(0, n - 1);
    Get_PreTree(root, 1);
    for (int i = 1; i <= dl; i++)
    {
        if (i % 2 == 0)
            for (int j = 0; j < ans[i].size(); j++)
                printf("%d ", ans[i][j]);
        else
            for (int j = ans[i].size() - 1; j >= 0; j--)
                printf("%d ", ans[i][j]);
    }
    return 0;
}