#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans,x;
int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    scanf("%d",&ans);
    for (int i=1;i<n;i++)
        scanf("%d",&x),ans=lcm(ans,x);
    printf("%d",ans);
    return 0;
}