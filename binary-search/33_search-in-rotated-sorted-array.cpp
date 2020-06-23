// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
	// 将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
	// 此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环.
	// 4ms,6.5MB
    int search(vector<int>& nums, int target) {
		int count = nums.size();
		if (count == 0)
			return -1;
		int left = 0;
		int right = count - 1;
		while (left<=right)
		{
			int mid = left/2 + right - right / 2;
			if (nums[mid] == target)
				return mid;
			//说明左边是有序的，右边可能是有序的
			else if (nums[left] <= nums[mid])
			{
				//左侧有序但是不在这个范围，就直接跳过
				if (nums[left] > target || nums[mid] < target)
				{
					left = mid + 1;
					continue;
				}
				//在左侧这个有序范围
				else
				{
					right = mid - 1;
					continue;
				}
			}
			//说明右边是有序的，左边可能是
			else
			{
				//右侧有序，但是不在这个范围
				if (nums[mid] > target || nums[right] < target)
				{
					right = mid - 1;
					continue;
				}
				//在右侧这个有序范围
				else
				{
					left = mid + 1;
					continue;
				}
			}
		}
		return -1;
	}
};