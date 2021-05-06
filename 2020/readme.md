## 破解角度

1. 将数字看成32bit， 考虑每一个bit的情况。

2. 动态规划。

3. int中只取最后一位1的数字位last=r & (~(r-1))。去掉最后一位1：r & (r-1)。

4. 动态规划+记账功能。


## 总结

角度：大局分解或者step渐进。

逻辑较多时，可以对处理步骤进行分函数。

#### 1.two sum

在数组中找两数之和等于给定目标值。

简单。

#### 2. add two num

求两个链表数之和。

简单。

#### 3. longest substring without repeating characters

找一个字符串中最长子串的长度，要求改子串中不能有重复字母。

简单。

#### 4.median-of-two-sorted-arrays

求两个已排序数组，它们的中位数。

困难。

#### 5. longest palindromic substring

求最长回文子串。

简单。

#### 9. palindrome number

判断一个int是否为回文数。

简单。

#### 11. container with most water

一个int数组，每个数表示板高，求这些板能容纳最多的水。

简单。

#### 14. Longest Common Prefix

找一组字符串的最长公共前缀。

简单。

#### 15. 3 sum

求一个数组中3数之和等于0的组合，要求找出所有的组合且不能有重复。

简单。

#### 16. 3 sum closest

给定一个数组和一个target，求数组中三数之和，且该和最接近目标值。

简单。

#### 17.letter combinations of a phone number

给定一个电话号码串，给出它们所有的字母串，数字是按手机9宫格上的字母映射。

简单。

#### 18. 4 sum

给定一个数组，找出该数组中所有4数集，要求它们的和等于给定值且这些4元组不能有重复。

简单。

#### 19.remove Nth node from end of list

删除链表中倒数第n个结点，要求一次遍历。

简单。

#### 20.valid parentheses

判断括号"()[]{}"串是否匹配。

简单。

#### 21. merge two sorted lists

原地merge两个有序链表，要求合并后的链表也有序。

简单。

#### 22. generate parentheses

产生括号匹配个数。

简单。

#### 23. merge k sorted lists

将k个sort链表按序连接起来。

使用大根堆。

简单。

#### 24. swap nodes in pairs

把链表中没相邻两个结点交换一下位置。

简单。

#### 25. reverse nodes in k-Group

按段逆转链表，每k个结点作为一段，要求常量空间。

中等。

#### 26. remove duplicates from sorted array

从一个已排序数组中删除重复数，算法原地进行。

简单。

#### 27. remove element

删除一个数组中等于某值的数，算法原地进行。

简单。

##### 28. implement strStr

实现一个找子串strstr的功能。

简单。

#### 30. substring with concatenation of all words

给出一批字符串和一个大字符串，要求找出大字符串中，所有这批小串拼接起来的子串。

困难。

#### 32. longest valid parentheses

求一个()组成的字符串中，合法括号配对的最大长度。

用动态规划，一遍扫描即可。

中等。

#### 36. valid sudoku

验证数独是否合法。每行、每列，每3x3九宫格中不能含有重复数字。

简单。

#### 38. count and say

repeat count last word and speak: 1=>11=>21=>1211。

简单。

#### 44. wildcard matching

正则表达式匹配，包括"\*"和?两种。

递归，挨个字符比较。使用dp备忘录。

困难。

#### 46. permutations

一个数组中所有数字都不相同，枚举所有的排列情况。

中等。

递归枚举。


#### 49. group anagrams

找出一组字符串集合中，具有相同字母的字符串集。

简单。

##### 51. N queens

八皇后问题，要求枚举所有情况。

中等。

递归 + 记录出现标注。

#### 52. N-queens II

八皇后问题II，只要求算出出现次数。

中等。

#### 53. maximum subarray

求一个包含正负数数组中，连续子数组的最大和。

简单。

#### 54. spiral matrix

按外围环绕方式遍历矩阵。

简单。

分成四个方向遍历即可。

#### 56. merge intervals

合并区间。

sort区间by区间开始，然后合并即可。

中等-。

#### 58. length of last word

字符串包含字母和空格，求最后一个单词的长度。

简单。

#### 59. spiral matrix II

跟54，按外围环绕方式输出nxn矩阵。

简单。

#### 61. rotate list

逆转链表，从第k个结点开始逆转。

简单。

#### 64. minimum path sum

一个矩阵，只能从左往右，从上往下，求最左上角到最右下角所经路径的结点之和的最小值。

简单。

#### 66. plus one

vector int表示的大数，求其加1的结果。

简单。

#### 67. add binary

求两个二进制数之和， 数字用字符串来表示的。

简单。

#### 70. climbing stairs

爬楼梯，每步爬1格或2格，n格梯子一共有几种爬法。

简单。

#### 71. simplify path

精简路径，包括精简"/", ".", ".."。

简单。

#### 72. edit distance

求两个字符串的距离。

使用动态规划。

简单。

#### 73. set matrix zeroes

如果一个矩阵某个元素为0，则把它所在行和所在列都设为0。

要求原地设置矩阵。

把第一行和第一列用作标记， 标记该行/列是否存在元素0。

中等。

#### 74. search a 2d matrix

判断矩阵中是否存在一个数，该矩阵每行从左到右按序增大，且每行的第一个数比上一行的最后一个数字要大。

把该矩阵看作是一个一维数组，使用二分搜索即可以。

简单。

#### 75. sort colors

数组排序，数组只有数字0，1，2。要求一次遍历，原地排序。

使用start数组记录每个数字首次出现的位置。扫描该数组，当遇到cur小于prev时，则把首个start[k] >= 0的数跟当前cur交换位置，且k从cur+1开始递增。

中等。

#### 76.minimum-window-substring

求字符串中包含另一个字符串所有字母的最小窗口。

困难-。

#### 77. combinations 

求[1 .. n]中选k个数的组合。

递归，对i分选i和不选i的情况。

combinations[i; n, k] = combinations[i+1; n, k] + {i, combinations[i+1; n-1, k-1]}

中等。

#### 78. subsets

一个集合，里面各个元素各不相同。

求出该集合所有的子集。

递归，对元素，把它分到集合和部分集合两种情况。

中等。

#### 79. word search

查找一个字符二位数组中，是否存在一个字符串，字符数组中的字符可以横向和纵向。

递归，对二位数组中每个位置，搜索从该字符开始是否匹配该字符串。

中等。

#### 80. remove duplicates from sorted array

从一个排序数组中去除重复数字，使得结果中每个数字最多出现两次，要求原地操作。

遍历，记录上一个数字，以及它的出现次数和位置，左移到它旁边即可。

中等。

#### 82. remove duplicates from sorted list ii

有一个排序链表，如果一个结点出现重复，则把该数字从链表中去掉。

遍历，对结点p: 如果p->val == p->next->val，则把p及它的后续都删掉。

简单。

#### 83. remove duplicates from sorted list

有一个排序链表，如果一个结点出现重复，则把重复的元素去掉，但保留该数字。

遍历，对结点p：如果p->val == prev->val，则删除p。

简单。

#### 86 partition list

给定一个链表和一个值，把链表分成两段拼接起来，前一段的值小于该给定值，后一段的值大于等于该给定值。

要求这两段内的元素保持在原链表中的相对顺序。

简单。

#### 88 merge sorted array

原地合并两个有序数组，第一个数组的空间足够长。

简单。

#### 89 gray code

n bit 0-1s，要求相邻两数只有1bit不一样，求出其中一个排序。

简单。设定一个表，每次变动1bit，如果该数未曾出现过，则把它加入到列表中取。

#### 90 subsets ii

一个包含重复数字的数组，求所有不重复的子集。

先列举每个数字出现的次数，然后对value,  从0,1,...,count(value)加入到数组中，则可以求出所有的组合。

#### 91 decode ways

给出一个数字字符串，1~26分别解析成A~Z，问有多少种解析方法。

中等。

#### 93 restore ip addresses

0~9的字符串，可以有多少种ip的表示方式。

用动态规划。

简单。

#### 94 binary tree inorder traversal

求二叉树中序遍历，非递归算法。

用栈保存，不断push左孩子，在pop时再访问，访问完，再将右孩子入栈。

简单。

#### 95 unique binary search trees

求1-n二叉搜索树的所有情况。

递归。设左子树为left_vec, 右子树所有情况为right_vec，则本节点所有情况为：left_vec * right_vec。

中等。

#### 96 unique binary search trees

求1-2二叉搜索树的所有情况的个数。

dp[n] = sum(dp[k] * dp[i-k-1]);

简单。

#### 97 interleaving string

判断两个字符串交错拼接成另一个给定字符串。

使用动态规划。

中等。

#### 98 validate binary search tree

判断一个二叉树是否为搜索二叉树。

递归求解。

简单。

#### 100 same tree

判断两棵二叉树是否一样。

递归。

简单。

#### 101 symmetric tree

判断一棵二叉树是否左右对称的。

递归。

简单。

#### 102 binary tree level order traversal

按层输出二叉树的每一层节点。

使用队列。

简单。

#### 103 binary tree zigzag level order traversal

按层遍历，使用zigzag顺序，第奇数层从左往右，第偶数层从右往左。

使用双vector。

遍历偶数层时：

```c++
for (auto it=cur.rbegin(); it != cur.rend(); it++) {
   auto p = *it; 
   level.push_back(p->val);
   if (p->right) { other.push_back(p->right); }
   if (p->left) { other.push_back(p->left); }
}
std::reverse(other.begin(), other.end());
```

#### 104 maximum depth of binary tree

求树的最大深度。

递归。

简单。

#### 105 construct binary tree from preorder and inorder traversal

根据先序和中序遍历序，重构二叉树。

简单。

#### 106 construct binary tree from inorder and postorder traversal

根据后序和中序遍历序，重构二叉树。

简单。

#### 107 binary tree level order traversal ii

二叉树遍历，自底向上，从左往右。

简单。

#### 108 convert sorted array to binary search tree

将一个排序数组转化成平衡二叉搜索树。

递归，简单。

#### 110 balanced binary tree


判断一棵二叉树是否为平衡二叉树。

简单。

#### 111 minimum depth of binary tree

求二叉树的最小深度。

简单。

#### 112 path sum

判断一棵二叉树是否存在一个从根节点到叶子节点的路径，该路径所有节点之和为目标值。

简单。

#### 113 path sum ii

求出一棵二叉树中，所有从根节点到叶子节点的路径，使得该路径上所有节点之和为目标值。

简单。

#### 114 flatten binary tree to linked list

把二叉树转化成链表，left指针恒为0， right指针为先序遍历的下一个节点。

记录prev结点，然后prev->right = cur;

中等。

#### 116 populating next right pointers in each node

在一棵满二叉树中，设置节点的next为同level中下一个节点。要用原地算法，但可以使用递归。

```c++
p->left->next = p->right;
p->right->next = p->next->left;
```

简单。

#### 117.populating-next-right-pointers-in-each-node-ii

在任意一棵二叉树中，设置节点的next为同level中下一个节点。要用原地算法。

按层设置。

较困难。

#### 118.pascals-triangle

输出帕斯卡三角系数。

简单。

#### 119.pascals-triangle-ii

输出帕斯卡三角第n行的数据。

使用公式推导即可。

简单。

#### 120.triangle

一个三角阵，求从顶点到底边的连线的最小之和。从L层到达L+1层的节点i时，只能经过第L层的节点i-1或者节点i。

```c++
s[i] = min { s[i-1], s[i] } + triangle[i];
```

容易出错，使用上面的公式时，从L层到L+1层，应该先计算s[i]， 再计算s[i-1];

#### 121.best-time-to-buy-and-sell-stock

求出一个股票历史股价。从中找出两天，一天买入， 一天卖出。求最大利润。

简单。

#### 124.binary-tree-maximum-path-sum

求二叉树中某条路径的最大值

s(p) = max(s(p->left), s(p->right), max(p one side), max(p two side))

中等

#### 125.valid-palindrome

判断一个字符串是否为回文串，只考虑字符串中出现的字母和数字情况，且字母忽略大小写。

简单。

#### 129.sum-root-to-leaf-numbers

求二叉树中所有从根节点到叶子节点组成路径上数字之和。

简单。

#### 133.clone-graph

克隆一个图。

简单。用map记录下映射关系。

#### 136.single-number

一个数组，只有一个数字出现一次，其他数字都出现两次。求这个只出现一次的数字。

使用异或运算。

简单。

#### 137.single-number-ii

一个数组，只有一个数字出现一次，其他数字都出现三次。求这个只出现一次的数字。

```c++
for (auto num : nums) {
  bit_i = (bit_i + bit i of num) % 3
}

res = sum(bit_i << i)
```

#### 138.copy-list-with-random-pointer

链表中每个节点有一个random指针，指向链表中的某个节点。

深拷贝这种链表。

法一：使用map[origin node] = clone node记录；

法二： clone->next->random = p->next->random

中等。

#### 139.word-break

给定一个字典（多个单词）和一个字符串，判断该字符串是否可以由这个字典中的词语拼接组成，单词可以使用任意次数。

简单。用动态规划来判断。

#### 141.linked-list-cycle

判断链表是否有环。

简单。用两个指针，第一个每次移动一步，第二个每次移动两步，在判断这两个指针是否相等。

#### 144.binary-tree-preorder-traversal

非递归先序遍历二叉树。

使用栈。进栈时:
```c++
	for (; p!= nullptr; p=p->left) {
	  visit(p);
	  stk.push(p);
	}
```

中等。

#### 146.lru-cache

实现一个LRU cache，要求get/put的时间复杂度为O(1).

使用unordered_map和list来实现。

这里认为unordered_map的get/put的时间复杂度为O(1).

简单。

#### 149.max-points-on-a-line

给出二维平面上的多个点，问最多有几个点落在同一直线上。

以第i个节点作为考虑，依次考虑经过该点的直线中，最大的直线包含的顶点个数。

中等。

#### 150.evaluate-reverse-polish-notation

求逆波兰式的值。

用栈即可，简单。

#### 151.reverse-words-in-a-string

将一个句子中的单词逆序，且结果中单词之间为1个空格，去掉首尾空格。

两次逆序。

简单+。

#### 152.maximum-product-subarray

求整数数组中，连续最大子数组的乘积。

```c++
v1 = cur;
v2 = cmax * cur;
v3 = cmin * cur;

cmax = max(v1, v2, v3)
cmin = min(v1, v2, v3)
```

简单。

#### 155.min-stack

设计一个带min函数的栈。

用vector保存elem & min即可。

简单。

#### 160.intersection-of-two-linked-lists

求两个链表相交的第一个节点。

简单。

#### 165.compare-version-numbers

比较两个版本号的大小。

对这两个版本号，每次获取一个子版本号，如果当前已结束，则子版本号为0.

然后再比较这两个子版本号，如果不想等则返回。

简单。

#### 167.two-sum-ii-input-array-is-sorted

求排序数组两数之和等于给定值。

简单。

#### 169.majority-element

求一个数组中多数派数字。多数派是指出现次数超过半数以上。

简单。

#### 171.excel-sheet-column-number

求excel表头(A, B, C, ...) 转成数字。

简单。

#### 172.factorial-trailing-zeroes

求n阶乘中尾部0的个数。

count(tail 0) = n/5 + n/25 + n/125 + ...

简单。

#### 179.largest-number

给定一个非负整数数组，求拼接起来的最大数字，用字符串来表示。

```c++
sort(..., [](a, b) { return str(a) + str(b) > str(b) + str(a); }
```

简单。

#### 190.reverse-bits

求一个32位数字位逆转后的数字。

简单。

#### 191.number-of-1-bits

求32位二进制数中1的个数。

简单。

去掉最低位1的方法。

n &= (n-1);

#### 198.house-robber

房子抢劫，相邻两房不能抢，问最大抢劫货位数。

```c++
 new_cur = std::max(cur, pre + nums[i]);
 pre = cur;
 cur = new_cur;
```

#### 199.binary-tree-right-side-view

求二叉树中从右往左看的结点。

简单。

#### 200.number-of-islands

0-1组成的矩阵，求由1连起来的岛的个数。

中等。

#### 201.bitwise-and-of-numbers-range

求从m到n范围的所有整数的&之和。

求出从m到n，高位相同bit即可。

中等。

#### 203.remove-linked-list-elements

删除链表中等于给定值的节点。

简单。

#### 204.count-primes

求1到n之间素数的个数。

遍历1到n，用一个vector记录当前的素数，用vector中的元素试探当前元素是否为素数。

简单。

#### 205.isomorphic-strings

问两个string是否可以相互映射。

简单。但要注意是双射。

#### 206.reverse-linked-list

链表倒置。

简单。

#### 208.implement-trie-prefix-tree

构建一棵前缀树。

简单。

#### 209.minimum-size-subarray-sum

求一个正整数数组中最短连续子数组，它之和不小于给定目标值。

简单。

#### 211.design-add-and-search-words-data-structure

查找一个字符是否在给定字符串集中，包含通配符'.'。

简单。

#### 212.word-search-ii

从一个矩阵中找出所有unique的单词，单词根据给定字典给出。

中等。

#### 217.contains-duplicate

问一个数组中是否有重复数字。

用set统计。

简单。

#### 219.contains-duplicate-ii

求问一个数组中相邻为K的子数组中，是否包含有重复数字。

简单。

#### 220.contains-duplicate-iii

求一个数组中，是否存在两数，距离不超过k，他们之差不超过t。

维护一个长度为k的set集合，然后判断该集合即可。

中等。

#### 221.maximal-square

求一个0-1矩阵中由1组成的最大正方形面积。

```c++
if (ch == '0') {
   edge[i][j] = 0;
} else {
   edge[i][j] = min(edge[i-1][j-1], edge[i-1][j], edge[i][j-1]) + 1
}
```

中等。

#### 226.invert-binary-tree

二叉树左右子树互换。

简单。

#### 228.summary-ranges

求一个排序数组的范围描述。

简单。

#### 231.power-of-two

判断一个整数是否为2的幂。

```c++
   n > 0 && !(n & (n-1))
```

简单。

#### 232.implement-queue-using-stacks

用栈实现队列。

简单。

#### 235.lowest-common-ancestor-of-a-binary-search-tree

求二叉搜索树中两节点的最低公共父节点。

简单。

#### 237.delete-node-in-a-linked-list

链表中删除一个节点。

简单。

#### 239.sliding-window-maximum

一个数组，给该数组加上一个滑动窗口，窗口每次右移一个位置，求滑动窗口在右移过程中的窗口内的最大值。

用deque<int> 记录窗口内的元素下标，且满足 Q[0] > Q[1] > Q[2] ... 这样的顺序。则窗口内最多元素是nums[Q[0]]。

中等。

#### 240.search-a-2d-matrix-ii

在矩阵中查找一个元素是否存在，每一行中，元素自左向右递增；每一列中，元素自上向下递增。

可以跟矩阵右上角元素进行比较，每次只移动一行或一列。

简单。

#### 242.valid-anagram

判断两个字符串是否同构。

简单。

#### 260.single-number-iii

一个数组中除了两数分别只出现一次，其他的数字都是恰好出现两次。求这两个只出现一次的数字。

先异或所有数字，然后相当于a ^ b，从中找一位1，则把整个数组分成两半，一半为0，一半为1，然后对这两半分别求异或即可。

简单。

#### 263.ugly-number

判断一个数字是否为丑数：只能被2、3、5整除。

简单。

#### 264.ugly-number-ii

求第i个丑数。

中等。

#### 290.word-pattern

一个pattern和一个单词串，问pattern和单词串是否匹配。

简单。

#### 292.nim-game

一堆石子，每次只能取1~3个，你先取，你朋友再取。问你是否有必赢的方法。

#### 295.find-median-from-data-stream

从一个data stream中找中间元素。

简单。

#### 297.serialize-and-deserialize-binary-tree

设计一种将二叉树序列化和反序列的方式。

中等。

#### 299.bulls-and-cows

统计两个字符串中：位置一样的字符总个数和位置不一样但字符一样的总个数。

简单。

#### 303.range-sum-query-immutable

求一个数组其某段范围之和。

简单。

#### 304.range-sum-query-2d-immutable

求一个二位整数数组中，子矩阵中所有数之和。

简单。

#### 313.super-ugly-number

求第n个丑数。质因子由给定数组给出。

简单。

#### 319.bulb-switcher

灯泡开关，第i次每第i个拨动一次开关，问最后剩余几盏灯。

简单。sqrt(n)

#### 322.coin-change

有若干种货币面值，问一个数量，用最少个数的货币来表示，问这个最小的数。

使用动态规划。

简单。

#### 328.odd-even-linked-list

链表节点重连接，奇数序的在前面，偶数序的在后面。

#### 329.longest-increasing-path-in-a-matrix

求矩阵中最大路径长度，路径上的元素要求递增。

dp[i, j] = max { 周围比它大的节点的dp[i', j'] } + 1。

中等。

#### 331.verify-preorder-serialization-of-a-binary-tree

判断一个字符串是否为一棵二叉树的先序遍历，其中节点之间用','隔开，空节点用'#'表示。

模拟建树过程。

有代表性。

简单。

#### 334.increasing-triplet-subsequence

求数组中是否存在从左至右存在三个数 a 小于 b 小于 c。

非常经典。

中等。

#### 336.palindrome-pairs

字符串数组中，求出所有两个拼接起来可组成的回文串。

中等。

#### 337.house-robber-iii

强盗抢劫一棵树，相邻两个节点不能同时抢，问最大抢劫量。

典型。

N = max{ sum(node's child's max), p->val + sum(exclude child's max)}

中等。

#### 338.counting-bits

求0-n中各个数字的二进制表示中1出现个数。

count(i) = i & 1 ? count(i-1) + 1 : count(i>>1)

简单。

#### 341.flatten-nested-list-iterator

嵌套List要求支持next, hasNext操作。

使用栈操作。

简单。

#### 342.power-of-four

判断一个数是否为4的幂。

注意，是4的幂，不是4的倍数。

简单。

#### 343.integer-break

将一个正数拆出多个正数和，求出它们中最大的乘积。

简单。

#### 344.reverse-string

字符串逆序。

简单。

#### 345.reverse-vowels-of-a-string

将一个字符串中的原因逆序。

简单。

#### 347.top-k-frequent-elements

一个数组中，按出现次数倒排，求出现最频繁的k个数字。

简单。

#### 349.intersection-of-two-arrays

求两个数组的交集。unique。

简单。

#### 350.intersection-of-two-arrays-ii

求两个数组的交集。非unique。

简单。

#### 354.russian-doll-envelopes

求嵌套装信封的最大个数。

简单。

#### 355.design-twitter

求出twitter中关注者和自己最近post的10条tweet。

简单。

#### 357.count-numbers-with-unique-digits

求n位数字中各数字互不相同的数字有多少个。

简单。

#### 368.largest-divisible-subset

一个整数数组中，求出一个最大子集，使得该集合中任意两个数要么 a%b==0，要么b%a==0。

使用动态规划。

简单。
