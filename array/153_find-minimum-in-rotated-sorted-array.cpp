// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
	// 二分法，0ms,10MB
    int findMin(vector<int>& nums) {
        int minValue=nums[0];
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[l]<=nums[m]){
                minValue=min(nums[l],minValue);
                l=m+1;
            }
            else if(nums[m]<=nums[r]){
                minValue=min(nums[m],minValue);
                r=m-1;
            }
        }
        return minValue;
    }
};