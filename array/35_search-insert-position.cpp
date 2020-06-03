// https://leetcode-cn.com/problems/search-insert-position/
class Solution {
public:
	// 在从小到大的排序数组中，lower_bound( begin,end,num)：从数组的begin位置到end-1位置
	// 二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。
	// 通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
	// 4ms,6.7MB
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};