#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T, typename Compare = less<T>>
class Heap
{
private:
    vector<T> val;
    Compare cmp;

    int getCid(int idx)
    {
        return (idx << 1) | (lId + 1);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif

    return 0;
}