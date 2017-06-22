/*
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence
 *
 * Medium (28.05%)
 * Total Accepted:    81729
 * Total Submissions: 291340
 * Testcase Example:  '1\n1'
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        if(n<=0){
            return "";
        }
        
        vector<int> digits;
        int total = 1; 
        for(int i=1;i<=n;i++){
            total *= i;
            digits.push_back(i);
        }
        
        if(k<=0||k>total){
            return "";
        }
        
        int i = 0;
        k--;
        while(k){
            total /= (n-i);
            int j = k/total;
            int d = digits[i+j];
         
            digits.erase(digits.begin()+i+j);
            digits.insert(digits.begin()+i, d);
            
            k = k - int(k/total) * total;
            i++;
        }
        
        string res = "";
        for(int i=0;i<digits.size();i++){
            res += to_string(digits[i]);
        }
        
        return res;
    }
};
