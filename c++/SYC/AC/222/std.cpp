#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
map<char, int> mp;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> a;
    for (auto &&i : a)
        mp[i]++;
    int maxx = 'A';
    for (int i = 'A'; i <= 'E'; i++)
        if (mp[maxx] < mp[i])
            maxx = i;
    int sum = 0;
    for (int i = 'A'; i <= 'E'; i++)
        if (mp[i] == mp[maxx])
            sum++;
    if (sum>=2)
        printf("Nobody");
    else
        printf("%c",maxx);
    return 0;
}