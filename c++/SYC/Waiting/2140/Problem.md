### 题目描述

$Merlin$的朋友名单很长，他想向他们的每个人致以问候。

糟糕的是，$Merlin$的一个发件人名单很长，那些已经向他发送了邮件，他不想再发送任何邮件来打扰他们。

因此，在他开始发送消息之前，他需要弄清楚还有多少个朋友需要发送。请编写一个程序来帮助他。

$Merlin$的朋友列表没有排序，每个名字都是字母字符串，并且不区分大小写。这些名称保证不会重复。其次，某些发件人可能会向$Merlin$发送多个消息，因此发件人列表可能会重复。

$Merlin$广为人知，某些消息发件人甚至没有包含在他的朋友列表中。
### 输入格式
第一行都有两个数字$n$和$m(1 \leq n，m \leq 20000)$，这是朋友的数量和他收到的消息的数量。

然后有$n$行字母字符串（每个字符串的长度小于$10$），表示梅林的朋友的名字，前一行。 之后，有$m$行字母字符串$s$，它们是消息发送者的名称。

### 输出格式
输出一个整数，该整数指示他必须发送的剩余好友数。
### 输入样例
```
5 3
Inkfish
Henry
Carp
Max
Jericho
Carp
Max
Carp
```
### 输出样例
```
3
```