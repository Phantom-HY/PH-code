#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, x;
priority_queue<int, vector<int>, greater<int>> a;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        a.push(x);
        if (i>k)printf("%d ",a.top()),a.pop();
    }
    while (!a.empty())
    {
        printf("%d ",a.top()),a.pop();
    }
    return 0;
}