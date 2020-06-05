// https://leetcode-cn.com/problems/remove-element/
class Solution {
public:
	// 0ms,6.3MB
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != val)
                nums[k++] = nums[i];
        }
        return k;
    }
};