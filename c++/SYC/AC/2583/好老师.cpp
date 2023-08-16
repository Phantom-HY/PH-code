#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a[105];
int n, x, m;
void fun(int x)
{
    if (a[x] != "?")
    {
        cout << a[x] << '\n';
        return;
    }
    int i = x - 1, j = x + 1;
    while (i > 0 && a[i] == "?")
        i--;
    if (i <= 0)
        i = INT_MAX;
    while (j <= n && a[j] == "?")
        j++;
    if (j > n)
        j = INT_MAX;
    if (x - i == j - x)
    {
        cout << "middle of " << a[i] << " and " << a[j] << endl;
        return;
    }
    if (x - i < j - x && i!=INT_MAX)
    {
        for (int y = 1; y <= x - i; y++)
            cout << "right of ";
        cout << a[i] << '\n';
        return;
    }
    else
    {
        for (int y = 1; y <= j - x; y++)
            cout << "left of ";
        cout << a[j] << '\n';
        return;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        fun(x);
    }
    return 0;
}