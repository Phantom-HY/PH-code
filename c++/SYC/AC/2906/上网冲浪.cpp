#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b;
unordered_map<string, vector<string>> mp;
unordered_map<string, int> d;
bool vis[10005];
int n, m;
bool dfs(string st, string ed)
{
    // cout << st << '-' << ed << '\n';
    if (st == ed)
        return true;
    if (vis[d[st]] == 1)
        return false;
    vis[d[st]] = true;
    for (auto i : mp[st])
    {
        if (dfs(i, ed))
            return true;
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        d[a] = i;
        while (getline(cin, b), b != "</HTML>")
        {
            for (int i = 0; i < b.size(); i++)
            {
                int x = b.find("<A HREF=\"", i);
                if (x == -1)
                    break;
                string s = "";
                for (int j = x + 9; b[j] != '\"'; j++)
                    s += b[j];
                mp[a].push_back(s);
                i = x;
                cout << "Link from " << a << " to " << s << endl;
            }
        }
        // cout << b << "cs\n";
    }
    // for (auto &&i:mp)
    //     for (auto &&j:i.second)
    //         cout << i.first << " " << j << endl;
    // cout << endl;
    for (int i = 1; i <= m; i++)
    {
        memset(vis, 0, sizeof vis);
        cin >> a >> b;
        // cout << a << 'v' << b <<'\n';
        puts(dfs(a, b) ? "Yes." : "No.");
    }
    return 0;
}