/*
 * [423] Reconstruct Original Digits from English
 *
 * https://leetcode.com/problems/reconstruct-original-digits-from-english
 *
 * Medium (43.39%)
 * Total Accepted:    9951
 * Total Submissions: 22930
 * Testcase Example:  '"owoztneoer"'
 *
 * Given a non-empty string containing an out-of-order English representation
 * of digits 0-9, output the digits in ascending order.
 * 
 * Note:
 * 
 * Input contains only lowercase English letters.
 * Input is guaranteed to be valid and can be transformed to its original
 * digits. That means invalid inputs such as "abc" or "zerone" are not
 * permitted.
 * Input length is less than 50,000.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "owoztneoer"
 * 
 * Output: "012"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "fviefuro"
 * 
 * Output: "45"
 * 
 * 
 */
class Solution {
public:
    //traceback, time limit
    /*
    string helper(string cur, const vector<map<char,int>>& cnt, int num, int *left){
        bool valid = true;
        for(int i=0;i<26;i++) { 
            if (left[i] < 0) { return ""; }
            else if(left[i] > 0) { valid = false; }
        }
        if(valid) { return cur; }
        if(num > 9) { return ""; }
        
        int i = 0;
        bool ok = true;
        while(true){
            for(auto c : cnt[num]){
                if(left[c.first-'a'] < i * c.second) { ok = false; break; }
            }
            if(!ok) { break; }
            
            for(auto c : cnt[num]) { left[c.first-'a'] -= i * c.second; }
            string res = helper(cur + string(i, '0' + num), cnt, num + 1, left);
            if(!res.empty()) { return res; }
            for(auto c : cnt[num]) { left[c.first-'a'] += i * c.second; }
            
            i++;
        }
        
        return "";
    }
    
    string originalDigits(string s) {
        string w[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        vector<map<char, int>> cnt(10);
        for(int i = 0;i<=9;i++){
            for(auto c : w[i]) { cnt[i][c]++; }
        }
        
        int left[26];
        for(int i=0;i<26;i++) { left[i] = 0; }
        for(auto c: s) { left[c-'a']++; }
        
        return helper("", cnt, 0, left);
    }
    */
    string originalDigits(string s) {
        int a[10];
        for(int i=0;i<10;i++) { a[i] = 0; }
        for(auto c : s){
            switch(c) {
                case 'z': a[0]++; break;
                case 'w': a[2]++; break;
                case 'x': a[6]++; break;
                case 'u': a[4]++; break;
                case 'g': a[8]++; break;
                case 's': a[7]++; break; // 6 + 7
                case 'v': a[5]++; break; // 5 + 7
                case 'h': a[3]++; break; // 3 + 8
                case 'o': a[1]++; break; // 0 + 1 + 2 + 4
                case 'i': a[9]++; break; // 5 + 6 + 8 + 9
                default:;
            }
        }
        
        a[7] -= a[6];
        a[5] -= a[7];
        a[3] -= a[8];
        a[1] -= a[0] + a[2] + a[4];
        a[9] -= a[5] + a[6] + a[8];
        
        string res;
        for(int i=0;i<10;i++){
            res += string(a[i], i +'0');
        }
        
        return res;
    }
};
