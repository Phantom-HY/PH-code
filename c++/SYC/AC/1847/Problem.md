###  题目描述
给定三个整数数组

$A = [A_1,A_2,…A_N]$

$B = [B_1,B_2,…B_N]$

$C = [C_1,C_2,…C_N]$

请你统计有多少个三元组 $(i,j,k)$ 满足：

$1 \leq i,j,k \leq N,A_i \lt B_j \lt C_k$
### 输入格式
第一行包含一个整数 $N$。
第二行包含 $N$ 个整数 $A_1,A_2,\dots,A_N$。
第三行包含 $N$ 个整数 $B_1,B_2,\dots,B_N$。
第四行包含 $N$ 个整数 $C_1,C_2,\dots,C_N$。

### 输出格式
一个整数表示答案。
### 输入样例：
```
3
1 1 1
2 2 2
3 3 3
```
### 输出样例：
```
27
```
### 数据范围
对于全部数据:$1 \leq N \leq 10^5,0 \leq A_i,B_i,C_i \leq 10^5$