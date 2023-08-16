#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, l;
ll k;
map<char, string> zd;
string fun(string a)
{
    ll cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        cnt += a[i] - '0';
    }
    string ans = "";
    while (cnt != 0)
    {
        ans += cnt % 10 + '0';
        cnt /= 10;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    zd['a'] = "1", zd['b'] = "2", zd['c'] = "3", zd['d'] = "4", zd['e'] = "5", zd['f'] = "6", zd['g'] = "7",
    zd['h'] = "8", zd['i'] = "9", zd['j'] = "10", zd['k'] = "11", zd['l'] = "12", zd['m'] = "13", zd['n'] = "14",
    zd['o'] = "15", zd['p'] = "16", zd['q'] = "17", zd['r'] = "18", zd['s'] = "19", zd['t'] = "20", zd['u'] = "21",
    zd['v'] = "22", zd['w'] = "23", zd['x'] = "24", zd['y'] = "25", zd['z'] = "26",
    cin >> s >> k;
    for (int i = 0; i < s.size(); i++)
    {
        l += zd[s[i]];
    }
    while (k--)
    {
        l = fun(l);
        if (l.size() == 1)
        {
            break;
        }
    }
    for (int i = l.size() - 1; i >= 0; i--)
    {
        cout << l[i];
    }
    return 0;
}