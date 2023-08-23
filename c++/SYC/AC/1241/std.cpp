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
unordered_map<char, int> mp;
int paint(Tree *root)
{
    if (root == NULL)
        return 0;
    if (root->l == NULL && root->r == NULL)
        return mp[root->data] = 1;
    return mp[root->data] = paint(root->l) + paint(root->r);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> pre >> in;
    Tree *root = build_PostTree(0, pre.size() - 1);
    paint(root);
    for (int i = 0; i < pre.size(); i++)
    {
        for (int j = 1; j <= mp[pre[i]]; j++)
            printf("%c", pre[i]);
        puts("");
    }
    return 0;
}