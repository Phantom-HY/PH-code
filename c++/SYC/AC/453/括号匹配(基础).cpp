#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char x;
stack<char>a;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while(cin>>x)
    {
        if (x=='(')
            a.push(x);
        else
        {
            if (!a.empty())
                a.pop();
            else 
            {
                printf("No");
                exit(0);
            }
        }
    }
    if (a.empty())
        printf("Yes");
    else 
        printf("No");
    return 0;
}