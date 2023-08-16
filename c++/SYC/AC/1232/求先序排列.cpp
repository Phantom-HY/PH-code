#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Tree
{
    char data;
    Tree *l, *r;
};
string in, post; // post后序 in中序
int pos;
Tree *build_PreTree(int l, int r) // 求后序
{
    if (l > r)
        return NULL;
    Tree *root = new Tree();
    int p = in.find(root->data = post[pos--]);
    root->r = build_PreTree(p + 1, r);
    root->l = build_PreTree(l, p - 1);
    return root;
}
void Get_PreTree(Tree *root)
{
    if (root == NULL)
        return;
    cout << root->data;
    Get_PreTree(root->l);
    Get_PreTree(root->r);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> in >> post;
    pos = in.size() - 1;
    Tree *root = build_PreTree(0, in.size() - 1);
    Get_PreTree(root);
    return 0;
}