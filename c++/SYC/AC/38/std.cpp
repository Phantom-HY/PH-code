#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[10];
void fun(int x)
{
    while (x != 0)
    {
        ans[x % 10]++;
        x /= 10;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        fun(i);
    for (int i = 0; i < 10; i++)
        cout << ans[i] << "\n";
    return 0;
}