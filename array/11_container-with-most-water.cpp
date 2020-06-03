https://leetcode-cn.com/problems/container-with-most-water/
class Solution {
public:
    // 使用两个指针，值大的指针不动，而值小的指针向内移动遍历
    // 时间复杂度O(n)，空间复杂度O(1)
    // 12ms,7.5MB
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int result = INT_MIN;
        while (start < end) {
            int area = min(height[end], height[start]) * (end - start);
            result = max(result, area);
            if (height[start] <= height[end]) {
                start++;
            } else {
                end--;
            }
        }
        return result;
    }
};