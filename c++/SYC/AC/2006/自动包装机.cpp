#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, v;
queue<char> s[105];
stack<char> cnt;
char x;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            s[i].push(x);
        }
    while (scanf("%d", &v), v != -1)
    {
        if (v == 0)
        {
            if (cnt.size())
                printf("%c", cnt.top()), cnt.pop();
        }
        else
        {
            if (cnt.size() == k)
                printf("%c", cnt.top()), cnt.pop();
            if (s[v].size())
                cnt.push(s[v].front()), s[v].pop();
        }
    }
    return 0;
}