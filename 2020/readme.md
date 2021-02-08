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
