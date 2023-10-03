#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<int> a;
priority_queue<int, vector<int>, greater<int>> b;
int m, n;
int A[30005], u[30005];
void fun(int k)
{
    if (b.size() < k)
        while (b.size() != k && !a.empty())
            b.push(a.top()), a.pop();
    if (b.size() > k)
        while (b.size() != k && !b.empty())
            a.push(b.top()), b.pop();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &u[i]);
    int i = 1;
    for (int j = 1; j <= n; j++)
    {
        if (b.size() == 0 || A[j] >= b.top())
            b.push(A[j]);
        else
            a.push(A[j]), fun(u[i] - i + 1);
        while (u[i] == j)
        {
            fun(u[i] - i + 1);
            printf("%d\n", b.top());
            i++;
        }
    }
    return 0;
}