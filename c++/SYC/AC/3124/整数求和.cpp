#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
int ans[500005];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin>>a;
    ans[1]=a[0]-'0';
    for (int i=1;i<a.size();i++)ans[i+1]=ans[i]+a[i]-'0';
    for (int i=a.size();i>=1;i--)
    {
        ans[i-1]+=ans[i]/10;
        ans[i]%=10;
    }
    int i=1;
    if (ans[0]!=0)i=0;
    for (;i<=a.size();i++)cout <<ans[i];
    return 0;
}