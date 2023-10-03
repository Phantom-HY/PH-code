#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<int> a;
priority_queue<int, vector<int>, greater<int>> b;
int n;
int s[200005];
void fun(int k)
{
    if (b.size() < k)
        while (b.size() != k && !a.empty())
            b.push(a.top()), a.pop();
    if (b.size() > k)
        while (b.size() != k && !b.empty())
            a.push(b.top()), b.pop();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &s[i]);
    for (int k = 1, i = 1; i <= n; k ++)
    {
        for (; i <= k * 2 - 1; i++)
        {
            fun(k);
            if (b.size() == 0 || s[i] >= b.top())
                b.push(s[i]);
            else
                a.push(s[i]), fun(k);
        }
        fun(k);
        printf("%d\n", b.top());
    }
    return 0;
}