// https://leetcode-cn.com/problems/longest-consecutive-sequence/
class Solution {
public:
	// 24ms,10.8MB
    int longestConsecutive(vector<int>& nums) {
        int ans(0);
        unordered_map<int, int> dp;
        
        for (auto &&x : nums){
            if (!dp[x]) dp[x - dp[x - 1]] = dp[x + dp[x + 1]] = dp[x] = dp[x - 1] + dp[x + 1] + 1;
            ans = max(ans, dp[x]);
        }

        return ans;
    }  

};