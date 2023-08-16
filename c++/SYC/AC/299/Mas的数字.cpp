#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,g[3]={2,3,5};
priority_queue<ll,vector<ll>,greater<ll>>b;
priority_queue<ll,vector<ll>,greater<ll>>ans;
set<ll>a;
int main(){
    scanf("%d",&n);
    a.insert(2),a.insert(3),a.insert(5);
    b.push(2),b.push(3),b.push(5);
    for (int i=1;i<=10000;i++)
    {
        ll x=b.top();
        b.pop();
        for (int j=0;j<3;j++)
            if (!a.count(g[j]*x))
                a.insert(g[j]*x),b.push(g[j]*x);
        ans.push(x);
    }
    n--; 
    while(n--)
        ans.pop();
    printf("%lld\n",ans.top());
    return 0;
}