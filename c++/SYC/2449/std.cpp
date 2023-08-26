#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct Tree
{
    string data;
    bool tag = 0;
    map<string, Tree *> mp;
};
string str;
Tree *root = new Tree;
void init(int l, Tree *root)
{
    if (l >= str.size())
        return;
    string s = "";
    for (; l < str.size() && str[l] != '\\'; l++)
        s += str[l];
    Tree *node = new Tree;
    if (l == str.size())
    {
        node->data = s;
        root->mp[s] = node;
        return;
    }
    if (root->mp[s] == NULL)
    {
        root->mp[s] = node;
        node->tag = 1;
        node->data = s;
    }
    else
        node = root->mp[s];
    init(l + 1, node);
}
void Get_Tree(Tree *root, int sum)
{
    for (int i = 1; i <= sum; i++)
        cout << ' ';
    cout << root->data << endl;
    for (auto &&i : root->mp)
        if (i.second->tag == 1)
            Get_Tree(i.second, sum + 2);
    for (auto &&i : root->mp)
        if (i.second->tag == 0)
            Get_Tree(i.second, sum + 2);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> n;
    root->data = "root";
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        init(0, root);
    }
    Get_Tree(root, 0);
    return 0;
}