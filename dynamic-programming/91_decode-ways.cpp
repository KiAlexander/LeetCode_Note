// https://leetcode-cn.com/problems/decode-ways/
class Solution {
public:
	// 实际上有两个约束条件，1. 0不能单独解码 2. 两位数必须在1与26之间。
	// 这道题目实际上就是约束版的f(n) = f(n-1) + f(n-2);，
	// 其中如果是s[n-1]为0，f(n-1) = 0，f(n) = f(n-2)，
	// 因为0无法单独解码，而f(n-2)的条件则是必须在1与26之间，否则f(n) = f(n-1)。 
	// 0ms,6.4MB
    int numDecodings(string s) {
        int cnt = 0;
        if(s.size() == 0 || (s.size() == 1 && s[0] == '0')) return 0;
        if(s.size() == 1) return 1;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.size(); ++i){
            dp[i+1] = s[i] == '0' ? 0 : dp[i];
            if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))){
                dp[i+1] += dp[i-1];
            }
        }
        return dp.back();
    }
};