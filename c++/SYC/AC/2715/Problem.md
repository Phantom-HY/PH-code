### 题目描述
给你一个整数数组 $nums$ 和一个整数 $k$ ，按以下方法修改该数组：

+ 选择某个下标 $i$ 并将 $nums[i]$ 替换为 $-nums[i]$

+ 重复这个过程恰好 $k$ 次。可以多次选择同一个下标 $i$

以这种方式修改数组后，输出数组可能的最大和

### 输入格式
第一行输出两个个正整数$n,k$
接下来一行$n$个整数$nums[i]$
### 输出格式
输出一个整数,表示修改后的数组最大和
### 输入样例1
```
3 1
4 2 3
```
### 输出样例1
```
5
```
### 输入样例2
```
4 3
3 -1 0 2
```
### 输出样例2
```
6
```

### 输入样例3
```
5 2
2 -3 -1 5 -4
```
### 输出样例3
```
13
```
### 数据规模
对于全部的数据$1 \leq n,k \leq 10^5,-10^9 \leq nums[i] \leq 10^9$