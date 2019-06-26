/*
 * [717] 1-bit and 2-bit Characters
 *
 * https://leetcode.com/problems/1-bit-and-2-bit-characters
 *
 * algorithms
 * Easy (53.36%)
 * Total Accepted:    4.9K
 * Total Submissions: 9.4K
 * Testcase Example:  '[1,0,0]'
 *
 * We have two special characters. The first character can be represented by
 * one bit 0. The second character can be represented by two bits (10 or
 * 11).  
 * 
 * Now given a string represented by several bits. Return whether the last
 * character must be a one-bit character or not. The given string will always
 * end with a zero.
 * 
 * Example 1:
 * 
 * Input: 
 * bits = [1, 0, 0]
 * Output: True
 * Explanation: 
 * The only way to decode it is two-bit character and one-bit character. So the
 * last character is one-bit character.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * bits = [1, 1, 1, 0]
 * Output: False
 * Explanation: 
 * The only way to decode it is two-bit character and two-bit character. So the
 * last character is NOT one-bit character.
 * 
 * 
 * 
 * Note:
 * 1 <= len(bits) <= 1000.
 * bits[i] is always 0 or 1.
 * 
 */
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
		int len = bits.size();
		for(int i=0;i<len;i++){
			if(bits[i]==1){
				i++;
			}
			else if(i==len-1){
				return true;
			}
		}

		return false;
    }
};
