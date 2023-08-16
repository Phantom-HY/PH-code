### 题目描述
二叉树是具有根节点的树,其中每个节点最多有两个子节点

您的任务是编写一个程序,该程序读取有根二叉树$T$并为$T$的每个节点$u$打印以下信息：

+ 节点编号

+ 父节点编号

+ 兄弟节点编号

+ 孩子的数量

+ 节点深度

+ 节点高度

+ 节点类型(`root`, `internal node` or `leaf`)

如果两个节点具有相同的父节点,则它们是兄弟节点

如果$u$和$v$有相同的父母,我们说$u$是$v$的兄弟(反之亦然)

树中节点的高度是从节点到叶子的最长简单向下路径上的边数

给一颗由 $n$ 个节点组成的二叉树,每个节点都有一个从 $0 \sim n-1$的唯一 $\text{id}$
### 输入格式
输入的第一行包括一个整数$n(1 \leq n \leq 25)$ 即树的节点数

在接下来的$n$行中,每个节点的信息以以下格式给出：

```
idx left right
```

$\text{idx}$是节点编号 ,$\text{left}$是左孩子节点编号,$\text{right}$是右孩子节点编号

如果节点没有左(右)孩子,左(右)由表示`-1`
### 输出格式
按照节点编号升序输出并按以下格式打印每个节点的信息：

```
node id: parent = p, sibling = s, degree = deg, depth = dep, height = h, type
```

$p$是其父级的编号 , 如果节点没有父节点,则打印`-1`.

$s$是其兄弟的编号 , 如果节点没有兄弟节点,则打印`-1`.

$\text{deg,dep,h}$ 分别是节点的子节点数、深度和高度

$\text{type}$是由字符串表示的节点类型(`root`, `internal node` or `leaf`

如果根可以被视为叶子或内部节点,则打印`root`
### 输入样例
```
9
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
```
### 输出样例
```
node 0: parent = -1, sibling = -1, degree = 2, depth = 0, height = 3, root
node 1: parent = 0, sibling = 4, degree = 2, depth = 1, height = 1, internal node
node 2: parent = 1, sibling = 3, degree = 0, depth = 2, height = 0, leaf
node 3: parent = 1, sibling = 2, degree = 0, depth = 2, height = 0, leaf
node 4: parent = 0, sibling = 1, degree = 2, depth = 1, height = 2, internal node
node 5: parent = 4, sibling = 8, degree = 2, depth = 2, height = 1, internal node
node 6: parent = 5, sibling = 7, degree = 0, depth = 3, height = 0, leaf
node 7: parent = 5, sibling = 6, degree = 0, depth = 3, height = 0, leaf
node 8: parent = 4, sibling = 5, degree = 0, depth = 2, height = 0, leaf
```
### 样例解释
![](https://syc-oj-file.oss-cn-shenzhen.aliyuncs.com/img/20210929113638244.jpg)