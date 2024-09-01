#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
map<int,int>mp;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d\n",&q);
    while(q--)
    {
        char op;
        int x;
        scanf("%c %d\n",&op,&x);
        if (op == '+')
            mp[x]++;
        if (op == '-')
            mp[x]--;
        if (op == '?')
        {
            int ans = -1e9;
            for (auto &&i : mp)
            {
                if (i.second > 0)
                    ans = max(ans,x^i.first);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}