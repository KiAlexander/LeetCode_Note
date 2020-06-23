// https://leetcode-cn.com/problems/maximum-subarray/
class Solution {
public:
	// 0ms,7.1MB
    int maxSubArray(vector<int>& nums) {
        int Ret=nums[0],sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            Ret=Ret>sum?Ret:sum;
            if(sum<0)sum=0;
        }
        return Ret;
    }
};