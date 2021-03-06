# 总结：

1. 考察是否具有递推性， 一般为连续的序列或者树中的连续路径（可以横跨左右子树）。 f(n) = f(n-1)??  常见解法：cur - global 方法 
题目：3
对于树也一样，考察当前节点为终点的序列，
题目：124
矩阵中的路径也一样
题目：329： (套路：dfs + cache)

递归的一种情况：
如果定义本身是一种递归的情况，则求解时可以使用递归求解。
题目：394

2. 出现n, k等等字眼， f[n][k] = ...??  常见解法： 动态规划
题目：5

回文字符串中， start - end 两个位置包含了n, k

3. 两边向中间夹逼，例如求两数和等于某数，
题目：11

4. 数据结构设计：
列表型删除或更新一个元素O(1):
1)用list 
2)vector { back <-> i && pop_back }

5. 求最大连通分量

6. dfs

7. 滑动窗口 
设置一左边界，当前窗口不满足时，左边界不断往右移动
题目：134

8. 分析数据结构的特点=>递归得到的特点
题目：671, 先分析该树的特点： 父节点=min(左孩子结点，右孩子结点) ==> 根结点是最小结点 ==> 只要找出比根结点大的最小结点即可。

角度：
当前判断+递归法（669）

# 题目

#### 1 two sum 求数组中两数和为target
一次遍历，使用哈希表记录数字，判断target - num是否在哈希表中

#### 2 add two numbers 两数和
两数和，数字用链表来表示。

##### 3 longest substring without repeating characters 字符串中不重复的子串的最大长度
使用 cur - max 方法：
cur = min { cur + 1, i - last_ccur }

##### 5 longest palindromic substring 最长回文子串
使用动态规划， dp[i][j] 表示i-j是否为回文串

##### 6 zigzag conversion 按zigzag组织字符串，再输出 
使用多层vector保存每行的字母

##### 7 reverse integer 将整数倒置
将整数倒置，当数字溢出时返回0

使用long来保存数据，当 y != int(y) 时表示溢出了。

##### 9 palindrome number 判断一个整数是否为回文数

判断 reverse(x) == x 即可

##### 11 container with most water 板块序列中，找出两块板之间能盛的最多水量  
从两边往里靠，每次移动较小一方的板。类似贪心算法。 

##### 15 3sum 求数组中三数和为0的所有可能unique情况
先排序，然后从头往后找，每次找两数和为-a[i]，时间复杂度为O(n^2)

##### 16 3sum closest 找出数组中三数和和给定目标最接近
先排序，然后从头往后找，每次找的目标为-a[i]，找到则直接返回target，否则继续找

##### 17 letter combinations of a phone number  电话号码组成的字符串

迭代号码 d => word + [dict of (d)]

##### 18 4sum 求数组中四数和为0的所有unique情况
类似3sum，从排序，从左边找两数，然后再找两数和为0，时间复杂度为O(n^3)

##### 19 remove nth node from end of list
一个快指针，一个慢指针，快指针先移动 n-1 步；接着移动两个指针，并且记录慢指针的前一个指针。

##### 20 valid parentheses  判断括号序列是否正确

遍历，使用栈

##### 21 merge two sorted lists 合并两个排序的链表

遍历，保存当前节点

##### 22 generate parentheses n个(和n个)的正确匹配枚举
递归可得， helper(res, s, left, right)
f(n) = sum { f(i) * f(n-i) },  i = 1, 2, ..., n-1

##### 23 merge k sorted lists 合并k个有序链表
使用大根堆优先队列进行合并

```c
struct cmp{
	bool operator()(ListNode* l, ListNode* r){
		return l->val > r->val;
	}
}
```

##### 24 swap nodes in pairs 交换链表中奇偶位置的两个结点

遍历交换每两个结点

##### 26 remove duplicates from sorted array 排序数组中删除重复元素

```c
k = 0
for(i=1;i<size;i++){
	if(a[i]!=a[k]){
		a[++k] = a[i];
	}
}
```

##### 27 remove element 删除数组中某个元素

##### 28 implement strstr 子串查找

##### 30 substring with concatenation of all words 给定一个词典，且词典中的词等长，找出一个字符串中所有子串，使得其恰好包含词典中所有的词。
从字符串任一位置开始，判断其是否恰好包含这个词典中的所有词。

##### 31 next permutation 求数组按大小排列的下一个较大数
O(n)时间复杂度，O(1)空间复杂度
从尾部往左，找出第一个满足a[i]<a[i+1]的数a[i]，然后从尾部找出第一个大于a[i]的数a[j]，i, j位置交换，接着a[i+1, ... n-1]之间的数值颠倒过来

##### 49 group anagrams 字符串数组按字符出现的次数分组 
使用哈希表记录每个字符串中各个字符出现的次数，并作为Key保存在另一个哈希表中。

##### 51 n-queue n皇后问题
使用dfs来求解

##### 52 n-queue ii n皇后问题
使用dfs来求解

##### 76 minimum window substring 对某字符串，寻找包含给定字符串的最小窗口
使用滑动窗口， 向右移动，在满足包含字符串的情况下，窗口左边不断向右移动
i => m[s[i]]--; 
if(m[s[i]] >= 0) count --

if(count==0){
	while(start <= i && m[s[start]] < 0){
		m[s[start++]]++;
	}

	//check is minimum window
}

##### 84 largest rectangle in histogram  竖方图中的最大矩形面积
尾部加0， 使用栈保存元素， 是的栈中元素保持增量的排序， 则当前元素较小时， 退栈并且计算当前矩形的面积。

##### 120 triangle 杨辉三角路径的最小和
O(n)的时间复杂度，自上向下计算
v[i] = min(v[i-1], v[i]) + triangle[i]

##### 128 longest consecutive sequence  求数组中最长连续子数列的长度
使用边界记录  
left = m[num-1]
right = m[num+1]
m[num] = m[num-left] = m[num+right] = left + right + 1

这样记录之后，对于一个边界 [a, b]， 一定会有 m[a]=m[b]=a,b之间的个数

##### 134 gas station 环状加油站，能否环跑一圈，能的话从第几个加油站开始
使用滑动窗口
total += gas[i] - cost[i]
cur += gas[i] - cost[i] 
当cur < 0时，窗口左边界不断右移动
最后判断total是否 >= 0，是的话则返回左边界

##### 138 copy list with random pointer 拷贝包含有随机指针的链表 
先拷贝一个链表p1->q1->p2->q2->p3->q3-> ...，接着拷贝随机指针 q->random = p->random->next，最后把p, q指针分离

##### 139 word break 字符串切分成词
1. 使用动态规划，复杂度为O(n^2) 
   dp[i] |= dp[j] && (s[j..i] in dict) (j=0,...,i)
2. 使用递归，指数复杂度
   helper(s, dict) => (sub in dict) && helper(left, dict)
说明：很多指数复杂度的递归考虑能否改成动态规划，动态规划实际上是添加备忘本，避免指数过程中的重复计算

##### 150 evaluate reverse polish notation 逆波兰式
使用栈

##### 208 implement trie prefix tree 构建词的前缀树
map[c] => postfix

##### 209 minimum size subarray sum  连续数列其和不低于s的最小区间长
使用queue，保证queue中和不低于s，大于s时则左边元素出队列，以求得最小值

##### 212 word search ii  寻找字符矩阵中能转成的多个单词， 单词由字典给出
trie + dfs 搜索可得

##### 213 house robber ii  环形房子抢钱，要求相邻两家不能同时被抢，求最大抢钱数
分奇偶计算 a = max(b, a+nums[i])   b = max(a, b+nums[i])算出来直线型的最大；
再计算[0,n-2] 和[1,n-1] 中的最大值，值得注意的是，注意房子数为1的情况

##### 239 sliding window maximum 求数组中滑动窗口的最大值
滑动窗口，使用队列，队列中的元素按下降排序，最大值为队头元素。

##### 274 h-index H指数 
排序 + 自右往左判断

##### 284 peeking iterator 增加支持peek(指下一个next)的函数
增加 cur 和 curValid 两个变量，分别指明下一个next的变量，以及cur是否有效。

##### 299 bulls and cows 计算两字符串匹配字符个数、匹配位置个数
匹配位置个数 + 匹配字符个数 = 相同字符出现的个数

##### 309 best time to buy and sell stock with cooldown 冷却1天的购买股票的最大收益
使用状态机，来进行转移：
s0(rest) :   rest => s0,   buy => s1 
s1(buy)  :   rest => s1,   sell => s2 
s2(sell) :   rest => s0,
使用装个状态机， max(s0[i], s1[i], s2[i])即为所求

##### 329 longest increasing path in a matrix 求矩阵中增量的最长路径
dfs + cache 来解决

##### 334 increasing triplet subsequence 数组中是否存在三数a[i]<a[j]<a[k] && i < j < k
记录两数c1, c2, 当前数<=c1时则更新c1, 否则<=c2时则更新c2,否则返回true

##### 368 largest divisible subset 数组中能连续整除的最大个数
先排序，在使用动态规划由右往左计算 dp[i] = (max(dp[j]) or 0) + 1，其中 nums[j]>=nums[i]

##### 377 combination sum iv 多个面值不一样的硬币组合成目标的序列个数，不同排序算不同的序列
1.考虑顺序列时(考虑i的最后一个元素为num)，对位置作外侧循环，内层为硬币种类，复杂度为O(n^2): dp[i] += dp[i - num]
2.不考虑顺序列时，对硬币种类作循环，复杂度为O(n): dp[i] += dp[i-num]

##### 380 insert delete getrandom O(1) 插入删除随机O(1) 
删除一个元素时，vector back => 删除位置，再pop_back，从而保证删除元素时复杂度也是O(1)
说明：vector删除一个元素时，可以把back挪到删除位置，再popback，则复杂度为O(1)

##### 386 lexicographial numbers 按字典顺序输出1-n的数字
使用递归   
helper(val) => visit(val) 
               for i = 0, 9 do helper(10*val + i)

##### 394 decode string   包含xx[yyy]型的字符串解码，xx表示重复次数
按照本身的定义可以使用递归，找出一对匹配的[]，然后进行分解： AB(f(A)+f(B)) 或 nA (n * f(A)) 的形式，递归可得。

##### 395 longest substring with at least k repeating characters 字符串中每个字符最少重复k次的最大长度
使用递归求解
f(s, k) => f(sx, k) sx 为s中不足k次字符切分的子串 

##### 399 evaluate division 计算变量商值 
找出有关联的变量，即找图的联通分量，每个联通子图中一律用其中一个变量来表示: 
b = ?? * a, c = ?? * a, ...

##### 424 longest repeating character replacement 求字符串中最多替换k个字符的连续repeat字符串长度
使用滑动窗口，记录当前字符出现的个数。 end - start + 1 - maxCount > k 时，表明start需要往右移动。

##### 438 find all anagrams in a string 对于两字符s, p, 查找s中所有包含跟p同构的字符串
滑动窗口,使用m记录字符出现的次数，并用count表示不为0的字符的个数
m[i] == 0 => count++;
m[i]++ 
m[i] == 0 => count--;

m[i-n+1] == 0 => count++;
m[i-n+1]--
m[i-n+1] == 0 => count--;

再判读count是否为0，为0表示恰好包含p的异构

##### 449 serialize and deserialize bst 二叉搜索树序列化和反序列化
序列化时，先根序遍历，变量值后加一个空格；反序列化时，维护一个栈，当前节点值小于栈顶节点值时，是其左节点，否则栈不断出栈，直到最后一个小于当前节点的节点，表明当前节点是其右孩子，最后当前节点入栈。

##### 467 unique substrings in wraparround string 在无穷字母表连环中，找出给定字符串的unique子串的出现次数
记录以字符x开头的连续子串的最大长度，则其长度==以x开头的子串的个数

##### 473 matchsticks to square 判断一堆火柴能否恰好组成一个正方形
深度遍历，使用s[4]保存四边的和，然后把当前边加入到这四边当中。

##### 525 contiguous array 找出出现等次数0和1的连续序列的最大长度
其中一个数字标记为1，另一数字标记为-1，等次数的连续序列 => sum = 0
s1 == s2 => p1,p2间的和为0 => 等次数

##### 592 fraction addition and subtraction 分数加减
a/b + c/d = (ad + bc)/(bd) => 再约分

##### 609 find duplicate file in system 寻找系统中有重复内容的文件
map<content, vector<path>> m 按内容索引文件名数组

##### 611 valid triangle number 求数组中能组成三角形的个数
先排序，对数组遍历， 使用队列保存当前右边能组成三角形的两边，对新遍历的边，如果无法再组成三角形了，则队列头部出头，复杂度为O(n^2)。

##### 621 task Scheduler 任务调度最小花费时间
按任务次数从大到小排序，每次从可选任务中选择剩余次数最大的，如果都不可选，则选择冷却时间最小的

##### 623 add one row to tree 树中添加一层子节点

##### 624 maximum distance in arrays 多个已排序数列的最大间隔差
一次遍历，记下当前数组和之前最大最小值的最大间隔，接着更新当前的最大最小值

##### 628 maximum product of three numbers 数组中求三数的最大值。
对数组排序，取 a[0] * a[1] * a[len-1] 和 a[len-1] * a[len-2] * a[len-3] 中较大者。

##### 629 k inverse pairs array 寻找1...n构成的数组中包含k个逆序对的个数
对最后一位数进行枚举，使用动态规划，dp[n][k] = dp[n-1][k-(n-1)] + dp[n-1][k-(n-2)] + ... + dp[n-1][k]

##### 633 sum of square numbers 判断某数是否为两个数的平方和
从 sqrt(val/2) 开始递减，判断val - a*a是否为平方数

##### 634 find the derangement of an array 求0-(n-1)错位的排列个数，错位是指 a[i] != i
递归 f(n) = (n-1)*(f(n-1) + f(n-2))

##### 637 average of levels in binary tree 二叉树每一层的平均数
使用递归求解

##### 645 set-mismatch 寻找重复以及丢失的数
1...n的数组中某数重复一次，某数丢失，寻找它们
两次遍历，一次找出重复的，一次找出丢失的。

##### 646 maximum length or pair chain 不相交区间的最大个数
使用贪心算法，对区间右侧进行排序，然后从左往右，依次选择可兼容的 

##### 647 palindromic substrings 求回文子串个数
使用动态规划算法
dp[i][j] = dp[i+1][j-1] && s[i]==s[j]

##### 652 find duplicate substrings 寻找二叉树中重复的子树，对于这些子树，只需要找出它们当中的一个根节点即可。

查找所有节点的后缀遍历串，并且增加一个map，保存每个这样串的出现次数，当出现次数==2时表示是重复了。

##### 653 two sum iv input is a bst 二叉搜索树数中判断两个结点和是否为k

遍历 + hash map

##### 654 maximum binary tree 根据数组构建二叉树，根结点为最大数

递归求解

##### 657 judge route circle 判断LRUD的一系列操作后是否回到原点
记录两个变量 left, up，LR修改left, UD修改up。
最后判断 left==0 && up==0

##### 658 find k closest elements 排序数组中找出k个和x最接近的数

```c
j = lower_bound(a.begin(), a.end(), x) - a.begin();
i = j - 1;

//a[i] < x <= a[j]
//然后从i和j向两边推进
```

##### 661 image smoother 图像按九宫格平滑

遍历计算即可。

##### 662 maximum Width of binary tree 树的最大宽度

递归遍历访问即可。

##### 665 non decreasing array 至多修改一个数，问该数列能否成为非减数列

当 a[i-1] > a[i] 时：
若 a[i-2] > a[i] 则 x = a[i-1] 否则为 a[i]
修改i-2, i-1, i这三数为 a[i-2], x, x

##### [E]669 trim a binary search tree 对二叉搜索树，给定区间，返回落在区间内的一棵二叉搜索树
递归遍历，不断判断当前结点是否落在给定区间

##### [E]671 second minimum node in a binary tree  查找二叉树中第二小的结点，该二叉树中父节点取孩子结点的最小值

先分析该树的特点： 父节点=min(左孩子结点，右孩子结点) ==> 根结点是最小结点 ==> 只要找出比根结点大的最小结点即可。

递归可解

##### [E] 674 longest continuous increasing subsequence 求数列中递增的连续子数列的最大长度

递增法：

```c
if(cur > pre){
	len++;
}
else{
	len = 1;
}
```

##### [E] 680 valid palindrome ii 判断某个字符串在最多删除一个字符的情况下，是否为回文串

```c
if(s[start++] != s[end--]){
	return is palindrome(s, start -1, end) || is palindrome(s, start, end + 1);
}
```

##### [E] 682 basketball game 篮球计分和 

分C(撤销),D(翻倍),+(前两轮之和),普通数字四种

一次遍历计算既可以

##### [E] 687 longest univalue path 求二叉树中相同结点路径的最大长度

求二叉树中相同结点路径的最大长度。

递归遍历即可以了。

##### [E] 690 employee importance 求员工及其下属的累加importance

建树，递归累加求和即可以了。

##### [E] 693 binary number with alternating bits

判断整数的各位相邻数字都是不同的

##### [E] 696 count binary substrings

求相等次数的01子串的个数

##### [E] 697.degree-of-an-array 数组的度定义为当中元素的最大出现次数，求连续子数组，且它的度等于给定其度，求出连续子数组的最短长度

```c
 for(int i=0; i<arr.len; i++){
	 int num = arr[i];
	 freq[num++];

	 if(!firstPos.count(num)){
		 firstPos[num] = i;
	 }

	 len = i - firstPos[num] + 1;
	 //update degree && min_len
	 if(freq[num] > degree){
		degree = freq[num];
		min_len = len;
	 }
	 else if(freq[num]==degree && len < min_len){
		 min_len = len;
	 }
 }
```

##### [E] 717 1 bit and 2 bit characters

两个字母A, B， A编码为0， B编码为10 或 11， 给定AB串的0-1编码串，问最后一个字符是哪个

一次遍历判断即可

##### [M] 718 maximum length of repeated subarray 求两个数组相同的公共子数组的最大长度

使用动态规划算法  dp[i][j] = A[i]==B[j] ? dp[i-1][j-1] + 1 : 0;
