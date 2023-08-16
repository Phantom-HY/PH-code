#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void fun()
{
    ll cnt = 0;
    char x[100005];
    cin>>x;
    for (int i=0;i<strlen(x);i++)
    {
        cnt += x[i] - '0';
    }
    cout<<(cnt+9) % 9<<'\n';
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin>>n;
    while (n--)
        fun();
    return 0;
}