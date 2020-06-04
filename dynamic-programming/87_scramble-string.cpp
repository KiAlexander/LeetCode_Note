// https://leetcode-cn.com/problems/scramble-string/
class Solution {
public:
	// 全局搜索
	// 4ms,7.6MB
    bool isScramble(string s1, string s2) {
        if (s1 == s2) 
            return true;
        int n = s1.size();
        int memo[26] = {0};
        for (int i = 0; i < n; ++i) {
           ++memo[s1[i] - 'a'];
           --memo[s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
           if (memo[i] != 0) 
               return false;
        }
        for (int i = 1; i < n; ++i) {
           if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) || (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))) {
               return true;
           }
        }
        return false;
    }
};