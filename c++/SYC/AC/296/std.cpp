#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
int ans[100005];
int s[100005], len;
int id[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int len = 0, cnt = 0, d = 1;
    while (cin >> c)
    {
        if (c == ')')
            ans[s[len--]] = d;
        else
            s[++len] = d, id[++cnt] = d;
        d++;
    }
    for (int i = 1; i <= cnt; i++)
        printf("%d\n", ans[id[i]]);
    return 0;
}