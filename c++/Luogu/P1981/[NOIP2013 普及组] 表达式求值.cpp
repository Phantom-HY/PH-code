#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a;
char b;
stack<int>x;
int ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&a);
    x.push(a%10000);
    while (scanf("%c%d",b,a)!=-1)
    {
        x.push(a%10000);
        if (b=='*')
        {
            int i=x.top(),j;
            x.pop();
            j=x.top(),x.pop();
            x.push((i*j)%10000);
        }
    }
    while(!x.empty())
    {
        ans+=x.top();
        x.pop();
        ans%=10000;
    }
    printf("%d",ans);
    return 0;
}