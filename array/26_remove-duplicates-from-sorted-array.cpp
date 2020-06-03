// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    // 16ms,7.6MB
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int k = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                nums[k++]=nums[i];
            }
        }
        return k;
    }
};