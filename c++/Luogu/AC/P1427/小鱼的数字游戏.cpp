#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x;
stack<int>a;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while(scanf("%d",&x),x!=0)
        a.push(x);
    while(!a.empty())
        printf("%d ",a.top()),a.pop();
    return 0;
}