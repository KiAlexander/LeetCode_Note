// https://leetcode-cn.com/problems/house-robber/
class Solution {
public:
	// 4ms,7.7MB
    int rob(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        vector<int> dp(n);
        if(n==0) return res;
        if(n<=2) return n==2?max(nums[0],nums[1]):nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};