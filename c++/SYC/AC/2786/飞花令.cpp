#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt_1,cnt_2;
string a,b;
queue<char>q;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin>>n>>a;
    a.erase(a.begin()+1);
    cin>>b;
    for (int i=0;i<n;i++)
        q.push('A'+i);
    while(cnt_1<a.size()&&cnt_2<b.size()&&q.size()>1)
    {
        auto u=q.front();
        q.pop();
        if (b[cnt_2]==a[cnt_1])
        {
            q.push(u),cnt_1++;
        }
        cnt_2++;
    }
    cout << q.front();
    return 0;
}