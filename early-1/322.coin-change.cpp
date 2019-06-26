/*
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change
 *
 * Medium (26.36%)
 * Total Accepted:    59291
 * Total Submissions: 224961
 * Testcase Example:  '[1]\n0'
 *
 * 
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * 
 * 
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 * 
 * 
 * 
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 * 
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<=0) { return amount ? -1 : 0; }
        int dp[amount+1];
        
        for(int i=0;i<=amount;i++){
            dp[i] = -1;
        }
        dp[0] = 0;
        
        for(int i=1;i<=amount;i++){
            int min = -1;
            for(int j=0;j<coins.size();j++){
                int coin = coins[j];
                if(i-coin >= 0 && dp[i-coin] >=0){
                    if(min==-1 || dp[i-coin] + 1 < min){
                        min = dp[i-coin] + 1;
                    }
                }
            }
            
            dp[i] = min;
        }
        
        return dp[amount];
    }
};
