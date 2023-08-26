#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<int> node[105];
int dep[105] = {0, 1};
int cnt[105] = {0, 1};
int ia = 1;
void fun(int x)
{
    if (cnt[ia] < cnt[dep[x]])
        ia = dep[x];
    for (auto &&i : node[x])
        dep[i] = dep[x] + 1, cnt[dep[i]]++, fun(i);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int id, k;
        scanf("%d%d", &id, &k);
        for (int j = 1; j <= k; j++)
        {
            int x;
            scanf("%d", &x);
            node[id].push_back(x);
        }
    }
    fun(1);
    printf("%d %d\n", cnt[ia], ia);
    return 0;
}