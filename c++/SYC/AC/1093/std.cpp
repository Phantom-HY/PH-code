#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long double pai = 3.14;
pair<string, long double> a[10005];
int n, r;
char s[1005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        long double C, S;
        C = a[i].second * 2 * pai;
        S = a[i].second * a[i].second * pai;
        cout << fixed << setprecision(0)<< a[i].first << " " << a[i].second << " ";
        cout << fixed << setprecision(1) << C << " " << S << "\n";
    }
    return 0;
}