// https://leetcode-cn.com/problems/subarray-sum-equals-k/
class Solution {
public:
	// 遍历数组nums，计算从第0个元素到当前元素的和，
	// 用哈希表保存出现过的累积和sum的次数。如果sum - k在哈希表中出现过，
	// 则代表从当前下标i往前有连续的子数组的和为sum。
	// 时间复杂度为O(n)，空间复杂度为O(n)
	// 116ms,26.7MB
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> cul;
        cul[0] = 1;
        for (auto &m : nums) {
            sum += m;
            res += cul[sum - k];
            ++cul[sum];
        }
        return res;
    }
};