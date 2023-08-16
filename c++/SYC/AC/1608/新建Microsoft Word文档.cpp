#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> a;
int n, k = 2, t[100005];
string cz;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    a.insert(1);
    cin >> n;
    while (n--)
    {
        cin >> cz;
        if (cz == "New")
        {
            printf("%d\n", *a.begin());
            t[*a.begin()]=1;
            a.erase(a.begin());
            if (a.empty())
                a.insert(k++);
        }
        else
        {
            int i;
            cin>>i;
            if (t[i]==1)
                printf("Successful\n"),t[i]=0,a.insert(i);
            else
                printf("Failed\n");
        }
    }
    return 0;
}