#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<int, int> a[1000005];
stack<pair<int, int>> q;
stack<int> ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].first), a[i].second = i;
    for (int i = n; i >= 1; i--)
    {
        while (!q.empty() && q.top().first <= a[i].first)
            q.pop();
        if (q.empty())
            ans.push(0);
        else
            ans.push(q.top().second);
        q.push(a[i]);
    }
    while (!ans.empty())
        printf("%d ", ans.top()), ans.pop();
    return 0;
}