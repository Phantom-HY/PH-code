#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
int n, x;
string a, b;
map<string, map<string, int>> m;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> x;
        m[b][a] += x;
    }
    for (auto &&i : m)
    {
        cout<<i.x<<'\n';
        for (auto &&j : i.y)
            cout<<"   |----"<<j.x<<'('<<j.y<<')'<<'\n';
    }
    return 0;
}