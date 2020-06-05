https://leetcode-cn.com/problems/single-number
class Solution {
public:
	// 异或
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(int i =0;i<nums.size();i++){
            a = nums[i]^a;
        }
        return a;
    }
};