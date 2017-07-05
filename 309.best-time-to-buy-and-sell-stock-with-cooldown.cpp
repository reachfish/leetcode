/*
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
 *
 * Medium (40.46%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like
 * (ie, buy one and sell one share of the stock multiple times) with the
 * following restrictions:
 * 
 * 
 * ⁠   You may not engage in multiple transactions at the same time (ie, you
 * must sell the stock before you buy again).
 * ⁠   After you sell your stock, you cannot buy stock on next day. (ie,
 * cooldown 1 day)
 * 
 * 
 * Example:
 * 
 * prices = [1, 2, 3, 0, 2]
 * maxProfit = 3
 * transactions = [buy, sell, cooldown, buy, sell]
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
	int max(int a, int b) { return a > b ? a : b; }

    int maxProfit(vector<int>& prices) {
		if(prices.size() <= 1) { return 0; }

		int res = 0;
		int s0 = 0, s1 = -prices[0], s2 = 0;
		int t0, t1, t2;
		for(int i=1;i<prices.size();i++){
			int price = prices[i];
			t0 = max(s0, s2);
			t1 = max(s0 - price, s1);
			t2 = s1 + price;

			s0 = t0;
			s1 = t1;
			s2 = t2;

			res = max(res, max(s0, max(s1, s2)));
		}

		return res;
    }
};
