#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
bool op(int x)
{
    int cnt = 0;
    while (x)
        cnt++,x/=10;
    return cnt == 5;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        int n, a;
        scanf("%d%d", &n, &a);
        int x = n * a;
        puts(op(x) ? "YES" : "NO");
    }
    return 0;
}