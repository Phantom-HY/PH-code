#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> ans;
void bdfs(int x, int step)
{
    if (step > n || x > n)
        return;
    if (step == n)
    {
        for (int i = 0; i < ans.size(); i++)
            printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : '+');
        return;
    }
    for (int i = x; i < n; i++)
        ans.push_back(i), bdfs(i, step + i), ans.pop_back();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin >> n;
    bdfs(1, 0);
    return 0;
}