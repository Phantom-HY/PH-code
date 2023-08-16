# Scarborough Fair

## 题面翻译

一个长度为n的字符串，需要做m个操作，每个操作有四个参数l,r,c1,c2，这意味着在(l,r)的范围中所有的符号c1(从l到r，包括l和r)都变成了c2。

第一行包含两个整数n和m (1<=n,m<=100)。

第二行包含一个长度为n的字符串，由小写的英文字母组成。

每个m行包含四个参数l,r,c1,c2(1<=l<=r<= n,c1和c2是小写英文字母),四个参数中间是隔开的空间。

执行上述操作后输出字符串s。

Translated by 我是lyy

## 题目描述

Are you going to Scarborough Fair?Parsley, sage, rosemary and thyme.

Remember me to one who lives there.

He once was the true love of mine.





Willem is taking the girl to the highest building in island No.28, however, neither of them knows how to get there.

Willem asks his friend, Grick for directions, Grick helped them, and gave them a task.

Although the girl wants to help, Willem insists on doing it by himself.

Grick gave Willem a string of length $ n $ .

Willem needs to do $ m $ operations, each operation has four parameters $ l,r,c_{1},c_{2} $ , which means that all symbols $ c_{1} $ in range $ [l,r] $ (from $ l $ -th to $ r $ -th, including $ l $ and $ r $ ) are changed into $ c_{2} $ . String is 1-indexed.

Grick wants to know the final string after all the $ m $ operations.

## 输入格式

The first line contains two integers $ n $ and $ m $ $ (1<=n,m<=100) $ .

The second line contains a string $ s $ of length $ n $ , consisting of lowercase English letters.

Each of the next $ m $ lines contains four parameters $ l,r,c_{1},c_{2} $ ( $ 1<=l<=r<=n $ , $ c_{1},c_{2} $ are lowercase English letters), separated by space.

## 输出格式

Output string $ s $ after performing $ m $ operations described above.

## 样例 #1

### 样例输入 #1

```
3 1
ioi
1 1 i n
```

### 样例输出 #1

```
noi
```

## 样例 #2

### 样例输入 #2

```
5 3
wxhak
3 3 h x
1 5 x a
1 3 w g
```

### 样例输出 #2

```
gaaak
```

## 提示

For the second example:

After the first operation, the string is wxxak.

After the second operation, the string is waaak.

After the third operation, the string is gaaak.