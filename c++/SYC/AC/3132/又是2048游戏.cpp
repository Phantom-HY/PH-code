#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10][10], b[10][10], n;
bool s[10][10];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    for (int x = 1; x <= 4; x++)
        for (int y = 1; y <= 4; y++)
            scanf("%lld", &a[x][y]);
    scanf("%lld", &n);
    if (n == 0) // 右
    {
        for (int x = 1; x <= 4; x++)//4
            b[x][4] = a[x][4];
        for (int x = 1; x <= 4; x++)//3
            if (b[x][4] == 0)swap(b[x][4], b[x][3] = a[x][3]);
            else if (b[x][4] == a[x][3] && !s[x][4])b[x][4] *= 2, s[x][4] = 1;
            else b[x][3] = a[x][3];
        for (int x = 1; x <= 4; x++)//2
            if (b[x][3] == 0)
                if (b[x][4] == 0)swap(b[x][4], b[x][2] = a[x][2]);
                else if (b[x][4] == a[x][2] && !s[x][4])b[x][4] *= 2, s[x][4] = 1;
                else b[x][3] = a[x][2];
            else if (b[x][3] == a[x][2] && !s[x][3])b[x][3] *= 2,s[x][3]=1;
            else b[x][2] = a[x][2];
        for (int x = 1; x <= 4; x++) // 1
            if (b[x][2] == 0)
                if (b[x][3] == 0)
                    if (b[x][4] == 0)swap(b[x][4], b[x][1] = a[x][1]);
                    else if (b[x][4] == a[x][1] && !s[x][4])b[x][4] *= 2, s[x][4] = 1;
                    else b[x][3] = a[x][1];
                else if (b[x][3] == a[x][1] && !s[x][3])b[x][3] *= 2, s[x][3] = 1;
                else b[x][2] = a[x][1];
            else if (a[x][1] == b[x][2] && !s[x][2])b[x][2] *= 2, s[x][2] = 1;
            else b[x][1] = a[x][1];
    }
    if (n == 1) // 下
    {
        for (int y = 1; y <= 4; y++) // 4
            b[4][y] = a[4][y];
        for (int y = 1; y <= 4; y++) // 3
            if (b[4][y] == 0)swap(b[4][y], b[3][y] = a[3][y]);
            else if (b[4][y] == a[3][y] && !s[4][y])b[4][y] *= 2, s[4][y] = 1;
            else b[3][y] = a[3][y];
        for (int y = 1; y <= 4; y++) // 2
            if (b[3][y] == 0)
                if (b[4][y] == 0)swap(b[4][y], b[2][y] = a[2][y]);
                else if (b[4][y] == a[2][y] && !s[4][y])b[4][y] *= 2, s[4][y] = 1;
                else b[3][y] = a[2][y];
            else if (b[3][y] == a[2][y] && !s[3][y])b[3][y] *= 2, s[3][y] = 1;
            else b[2][y] = a[2][y];
        for (int y = 1; y <= 4; y++) // 1
            if (b[2][y] == 0)
                if (b[3][y] == 0)
                    if (b[4][y] == 0)swap(b[4][y], b[1][y] = a[1][y]);
                    else if (b[4][y] == a[1][y] && !s[4][y])b[4][y] *= 2, s[4][y] = 1;
                    else b[3][y] = a[1][y];
                else if (b[3][y] == a[1][y] && !s[3][y])b[3][y] *= 2, s[3][y] = 1;
                else b[2][y] = a[1][y];
            else if (a[1][y] == b[2][y] && !s[2][y])b[2][y] *= 2, s[2][y] = 1;
            else b[1][y] = a[1][y];
    }
    if (n == 2) // 左
    {
        for (int x = 1; x <= 4; x++) // 1
            b[x][1] = a[x][1];
        for (int x = 1; x <= 4; x++) // 2
            if (b[x][1] == 0)swap(b[x][1], b[x][2] = a[x][2]);
            else if (b[x][1] == a[x][2] && !s[x][1])b[x][1] *= 2, s[x][1] = 1;
            else b[x][2] = a[x][2];
        for (int x = 1; x <= 4; x++) // 3
            if (b[x][2] == 0)
                if (b[x][1] == 0)swap(b[x][1], b[x][3] = a[x][3]);
                else if (b[x][1] == a[x][3] && !s[x][1])b[x][1] *= 2, s[x][1] = 1;
                else b[x][2] = a[x][3];
            else if (b[x][2] == a[x][3] && !s[x][2])b[x][2] *= 2, s[x][2] = 1;
            else b[x][3] = a[x][3];
        for (int x = 1; x <= 4; x++) // 4
            if (b[x][3] == 0)
                if (b[x][2] == 0)
                    if (b[x][1] == 0)swap(b[x][1], b[x][4] = a[x][4]);
                    else if (b[x][1] == a[x][4] && !s[x][1])b[x][1] *= 2, s[x][1] = 1;
                    else b[x][2] = a[x][4];
                else if (b[x][2] == a[x][4] && !s[x][2])b[x][2] *= 2, s[x][2] = 1;
                else b[x][3] = a[x][4];
            else if (a[x][4] == b[x][3] && !s[x][3])b[x][3] *= 2, s[x][3] = 1;
            else b[x][4] = a[x][4];
    }
    if (n == 3) // 上
    {
        for (int y = 1; y <= 4; y++) // 1
            b[1][y] = a[1][y];
        for (int y = 1; y <= 4; y++) // 2
            if (b[1][y] == 0)swap(b[1][y], b[2][y] = a[2][y]);
            else if (b[1][y] == a[2][y] && !s[1][y])b[1][y] *= 2, s[1][y] = 1;
            else b[2][y] = a[2][y];
        for (int y = 1; y <= 4; y++) // 3
            if (b[2][y] == 0)
                if (b[1][y] == 0)swap(b[1][y], b[3][y] = a[3][y]);
                else if (b[1][y] == a[3][y] && !s[1][y])b[1][y] *= 2, s[1][y] = 1;
                else b[2][y] = a[3][y];
            else if (b[2][y] == a[3][y] && !s[2][y])b[2][y] *= 2, s[2][y] = 1;
            else b[3][y] = a[3][y];
        for (int y = 1; y <= 4; y++) // 4
            if (b[3][y] == 0)
                if (b[2][y] == 0)
                    if (b[1][y] == 0)swap(b[1][y], b[4][y] = a[4][y]);
                    else if (b[1][y] == a[4][y] && !s[1][y])b[1][y] *= 2, s[1][y] = 1;
                    else b[2][y] = a[4][y];
                else if (b[2][y] == a[4][y] && !s[2][y])b[2][y] *= 2, s[2][y] = 1;
                else b[3][y] = a[4][y];
            else if (a[4][y] == b[3][y] && !s[3][y])b[3][y] *= 2, s[3][y] = 1;
            else b[4][y] = a[4][y];
    }
    for (int x=1;x<=4;x++)
        for (int y=1;y<=4;y++)printf("%lld%c",b[x][y],y==4?'\n':' ');
    return 0;
}