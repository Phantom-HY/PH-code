#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int maxn, minn;
string s;
map<int, int> cnt;
int main()
{
    cin >> s;
    int l = 0, r = s.size(), d = 1;
    while (l < r)
    {
        int x = 0, y = 0;
        while (l < r && s[l] != '+' && s[l] != '-' && s[l] != 'd')
            x = x * 10 + s[l++] - '0';
        if (s[l] == 'd')
        {
            if (x == 0)
                x = 1;
            l++;
            while (l < r && s[l] != '+' && s[l] != '-')
                y = y * 10 + s[l++] - '0';
            cnt[y] += x;
            if (d == 1)
            {
                maxn += x * y;
                minn += x;
            }
            else
            {
                maxn -= x;
                minn -= x * y;
            }
        }
        else
        {
            maxn += d * x;
            minn += d * x;
        }
        if (l < r)
            d = s[l++] == '+' ? 1 : -1;
    }
    for (auto i : cnt)
        cout << i.first << " " << i.second << "\n";
    cout << minn << " " << maxn;
    return 0;
}