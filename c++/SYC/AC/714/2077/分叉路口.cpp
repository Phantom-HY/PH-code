#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int fun(int x)
{
    if (x-k<=0||x-k&1==1)
        return 1;
    return fun(x-k>>1)+fun((x-k>>1)+k);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&k);
    printf("%d",fun(n));
    return 0;
}