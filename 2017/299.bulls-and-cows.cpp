/*
 * [299] Bulls and Cows
 *
 * https://leetcode.com/problems/bulls-and-cows
 *
 * Medium (34.31%)
 * Total Accepted:    56728
 * Total Submissions: 165318
 * Testcase Example:  '"1807"\n"7810"'
 *
 * You are playing the following Bulls and Cows game with your friend: You
 * write down a number and ask your friend to guess what the number is. Each
 * time your friend makes a guess, you provide a hint that indicates how many
 * digits in said guess match your secret number exactly in both digit and
 * position (called "bulls") and how many digits match the secret number but
 * locate in the wrong position (called "cows"). Your friend will use
 * successive guesses and hints to eventually derive the secret number.
 * 
 * 
 * For example:
 * 
 * Secret number:  "1807"
 * Friend's guess: "7810"
 * 
 * Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 * 
 * 
 * Write a function to return a hint according to the secret number and
 * friend's guess, use A to indicate the bulls and B to indicate the cows. In
 * the above example, your function should return "1A3B". 
 * 
 * Please note that both secret number and friend's guess may contain duplicate
 * digits, for example:
 * 
 * Secret number:  "1123"
 * Friend's guess: "0111"
 * 
 * In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a
 * cow, and your function should return "1A1B".
 * 
 * 
 * You may assume that the secret number and your friend's guess only contain
 * digits, and their lengths are always equal.
 * 
 * Credits:Special thanks to @jeantimex for adding this problem and creating
 * all test cases.
 */
/*
 * [299] Bulls and Cows
 *
 * https://leetcode.com/problems/bulls-and-cows
 *
 * Medium (34.31%)
 * Total Accepted:    56728
 * Total Submissions: 165318
 * Testcase Example:  '"1807"\n"7810"'
 *
 * You are playing the following Bulls and Cows game with your friend: You
 * write down a number and ask your friend to guess what the number is. Each
 * time your friend makes a guess, you provide a hint that indicates how many
 * digits in said guess match your secret number exactly in both digit and
 * position (called "bulls") and how many digits match the secret number but
 * locate in the wrong position (called "cows"). Your friend will use
 * successive guesses and hints to eventually derive the secret number.
 * 
 * 
 * For example:
 * 
 * Secret number:  "1807"
 * Friend's guess: "7810"
 * 
 * Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 * 
 * 
 * Write a function to return a hint according to the secret number and
 * friend's guess, use A to indicate the bulls and B to indicate the cows. In
 * the above example, your function should return "1A3B". 
 * 
 * Please note that both secret number and friend's guess may contain duplicate
 * digits, for example:
 * 
 * Secret number:  "1123"
 * Friend's guess: "0111"
 * 
 * In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a
 * cow, and your function should return "1A1B".
 * 
 * 
 * You may assume that the secret number and your friend's guess only contain
 * digits, and their lengths are always equal.
 * 
 * Credits:Special thanks to @jeantimex for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    string getHint(string secret, string guess) {
        int a[10], b[10];        
        int bull = 0;
        for(int i=0; i<10; i++) { a[i] = b[i] = 0; }
        for(int i=0;i<secret.size(); i++) { 
            a[secret[i]-'0']++; 
            b[guess[i]-'0']++; 
            if(secret[i] == guess[i]) { bull++; }
        }

        int cow = 0;
        for(int i=0;i<10;i++) { cow += a[i] <= b[i] ? a[i] : b[i]; }
        cow -= bull;

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

