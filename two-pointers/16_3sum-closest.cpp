// https://leetcode-cn.com/problems/3sum-closest/
class Solution {
public:
    // 1.
    // 8ms 10.2MB
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 3)
            return nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int a = nums[0] + nums[1] + nums[2];
		for(int i = 0; i < n; i++)
		{
			int l = i + 1;
			int r = n - 1;
			while(l < r)
			{
				int b = nums[i] + nums[r] + nums[l];
				a = abs(target - a) > abs(target - b) ? b : a;
				if(b == target) return b;
				else if( b > target) r--;
				else l++;
			}
		}
		return a;
    }

};