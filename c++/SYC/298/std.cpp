#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string str;
map<string, int> mp;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        string s;
        for (int j = 0; j < str.size(); j++)
        {
            s.push_back(str[j]);
            mp[s]++;
        }
    }
    cin >> str;
    string s;
    for (int i = 0; i < str.size(); i++)
    {
        s.push_back(str[i]);
        cout << mp[s] << "\n";
    }
    return 0;
}