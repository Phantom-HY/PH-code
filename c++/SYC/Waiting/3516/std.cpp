#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int a[10][10];
int dir[][2] = {{-1, -1}, {-1, 0}, {1, 0}, {1, 1}};
int f(int a[][10])
{
    int sum = 0;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j <= i; j++)
            sum += abs(a[i][j] - i);
    return sum;
}
struct node
{
    int a[10][10];
    int f, cnt;
};
void bfs()
{
    priority_queue<node> q;
    node start;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j <= i; j++)
            start.a[i][j] = i;
    start.f = f(start.a);
    start.cnt = 0;
    q.push(start);
    for (int i = 1; i <= 21;i++)
    {
        node e = q.top();
        
    }
    return - 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif

    return 0;
}