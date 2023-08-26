#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];
unordered_map<int, int> mp;
int ans[100005];
int dep;
int fun(int x)
{
    if (x == -1)
        return 0;
    return fun(a[x]) + 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i), mp[a[i]] = 1;
    for (int i = 0; i < n; i++)
        if (mp[i] == 0)
            ans[i] = fun(i), dep = max(dep, ans[i]);
    printf("%d\n", dep);
    for (int i = 0; i < n; i++)
        if (ans[i] == dep)
            printf("%d ", i);
    return 0;
}