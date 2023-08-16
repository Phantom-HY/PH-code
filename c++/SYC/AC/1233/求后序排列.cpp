#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Tree
{
    char data;
    Tree *l, *r;
};
string pre, in; // pre前序 in中序
int pos;
Tree *build_PostTree(int l, int r) // 求后序
{
    if (l > r)
        return NULL;
    Tree *root = new Tree();
    int p = in.find(root->data = pre[pos++]);
    root->l = build_PostTree(l, p - 1);
    root->r = build_PostTree(p + 1, r);
    return root;
}
void Get_PostTree(Tree *root)
{
    if (root == NULL)
        return;
    Get_PostTree(root->l);
    Get_PostTree(root->r);
    cout << root->data;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin>>pre>>in;
    Tree *root = build_PostTree(0, in.size() - 1);
    Get_PostTree(root);
    return 0;
}