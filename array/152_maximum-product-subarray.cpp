// https://leetcode-cn.com/problems/maximum-product-subarray/
class Solution {
public:
	// 先假设存在某个最大乘积，然后对数组遍历，在经过每个元素的时候，有以下四种情况：
	如果该元素为正数：
		如果到上一个元素为止的最大乘积也是正数，那么直接乘上就好了，同样的最大乘积也会变得更大
		如果到上一个元素为止的最大乘积是负数，那么最大乘积就会变成该元素本身，且连续性被断掉
	如果该元素为负数：
		如果到上一个元素为止的最大乘积也是负数，那么直接乘上就好了，同样的最大乘积也会变得更大
		如果到上一个元素为止的最大乘积是正数，那么最大乘积就会不变，且连续性被断掉
	以上四种情况中说到的最大乘积都是临时最大乘积，每遍历新的元素都需要进行比较来确定真正的最大乘积。
	// 8ms,11.5MB
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int max_v = 1, min_v = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) swap(max_v, min_v);
            max_v = max(max_v * nums[i], nums[i]);
            min_v = min(min_v * nums[i], nums[i]);
            ans = max(max_v, ans);
        }
        return ans;
    }
};