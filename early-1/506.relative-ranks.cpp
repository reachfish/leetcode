/*
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks
 *
 * Easy (46.78%)
 * Total Accepted:    15477
 * Total Submissions: 33081
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 */
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank = nums;
        sort(rank.rbegin(), rank.rend());
        
        map<int, string> m;
        for(int i=0;i<rank.size();i++){
            string r;
            switch(i){
                case 0: r = "Gold Medal"; break;
                case 1: r = "Silver Medal"; break;
                case 2: r = "Bronze Medal"; break;
                default: r = to_string(i+1);
            } 
            
            m[rank[i]] = r;
        }
        
        vector<string> res;
        for(auto num : nums) { res.push_back(m[num]); }
        return res;
    }
};
