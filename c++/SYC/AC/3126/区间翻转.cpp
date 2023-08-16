#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a[2];
string x;
int main()
{

    cin >> x;
    for (int i = 0; i < x.size(); i++)
    {
        a[i % 2].push_back(x[i]);
    }
    sort(a[0].begin(), a[0].end(), greater<char>());
    sort(a[1].begin(), a[1].end(), greater<char>());
    for (int i = 0; i < x.size(); i++)
    {
        cout << a[i % 2][i / 2];
    }
    return 0;
}