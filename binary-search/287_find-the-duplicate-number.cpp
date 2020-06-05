// https://leetcode-cn.com/problems/find-the-duplicate-number/
class Solution {
public:
    // 1.二分法
    // 时间O(nlogn)，空间O(1)
    // 28ms,10.7MB
    int findDuplicate(vector<int>& nums) {
        // 小于O(n^2) 二分查找
        // 我们不要考虑数组,只需要考虑 数字都在 1 到 n 之间
        // 示例 1:
        // arr = [1,3,4,2,2] 此时数字在 1 — 5 之间

        // mid = (1 + 5) / 2 = 3 arr小于等于的3有4个(1,2,2,3)，1到3中肯定有重复的值
        // mid = (1 + 3) / 2 = 2 arr小于等于的2有3个(1,2,2)，1到2中肯定有重复的值
        // mid = (1 + 2) / 2 = 1 arr小于等于的1有1个(1)，2到2中肯定有重复的值
        // 所以重复的数是 2 
        int left = 1;
        int right = nums.size();
        while (left < right){
            int mid = (left + (right - left)/2);
            int cnt = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] <= mid)
                   cnt += 1;
            }
            if(cnt <= mid)
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }

    // 2.二进制
    // 时间O(nlogn)，空间O(1)
    // 16ms,10.9MB
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        // 确定二进制下最高位是多少
        int bit_max = 31;
        while (!((n - 1) >> bit_max)) {
            bit_max -= 1;
        }
        for (int bit = 0; bit <= bit_max; ++bit) {
            int x = 0, y = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] & (1 << bit)) {
                    x += 1;
                }
                if (i >= 1 && (i & (1 << bit))) {
                    y += 1;
                }
            }
            if (x > y) {
                ans |= 1 << bit;
            }
        }
        return ans;
    }

    // 3.快慢指针
    // 时间O(n)，空间O(1) 
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }




};