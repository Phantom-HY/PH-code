#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string dp[2][105];
string add(string a, string b)
{
    string str;
    for (int i = a.size(); i < b.size(); i++)
        a += "0";
    for (int i = b.size(); i < a.size(); i++)
        b += "0";
    int m = 0;
    for (int i = 0; i < a.size(); i++)
    {
        str += (a[i] - '0' + b[i] - '0' + m) % 10 + '0';
        m = (a[i] - '0' + b[i] - '0' + m) / 10;
    }
    if (m != 0)
        str += m + '0';
    // cout << a << '+' << b << '=' << str << endl;
    return str;
}
void print(string str)
{
    for (int i=str.size()-1;i>=0;i--)
        cout << str[i];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    dp[0][1] = dp[1][1] = "1";
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = add(dp[0][i - 1], dp[1][i - 1]);
        dp[1][i] = dp[0][i - 1];
    }
    print(add(dp[0][n], dp[1][n]));
    return 0;
}