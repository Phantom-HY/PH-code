#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
map<string, bool> mp;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    while(n--)
    {
        cin>>s;
        if (s=="add")
        {
            getline(cin, s);
            mp[s] = true;
        }
        else
        {
            getline(cin, s);
            puts(mp[s] ? "yes" : "no");
        }
    }
    return 0;
}