// https://leetcode-cn.com/problems/wildcard-matching/
class Solution {
public:
	// 1.动态规划
	// 480ms,11.6MB
	 bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        
        for (int j = 1; j <= n; j++) {
            if(p[j - 1] == '*') dp[0][j] = true;
            else break;
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                } else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[m][n];
    }

    // 2.回溯
    // 12ms,6.5MB
    bool isMatch(string s, string p) {
        
        int i = 0;
        int j = 0;
        int star = -1;
        int k = 0; // 记录最后一次匹配的位置  + 1
        
        while (i < s.length()) {
            if (s[i] == p[j] || p[j] == '?') {
                ++i;
                ++j;
                continue;
            }
            
            if (p[j] == '*') {
                star = j++;
                k = i;
                continue;
            }
            
            // 如果失配了，回溯到 k + 1，即让 * 再多吞噬一个字符。
            if (star != -1) {
                i = ++k;
                j = star + 1;
                continue;
            }
            return false;
        }
        
        while (j < p.length() && p[j] == '*') ++j;
        
        return j == p.length();
    }
};