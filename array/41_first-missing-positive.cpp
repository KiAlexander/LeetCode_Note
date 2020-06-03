// https://leetcode-cn.com/problems/first-missing-positive/
class Solution {
public:
    //  假设原始数组为 A。先构造一个临时数组 tmp，初始化为 0，大小为A.size(). 
    // 遍历 A，把 A[i] 复制到 tmp[A[i]-1] 的位置。如果 A[i] - 1 超过了 tmp 的范围，
    // 就直接扔掉。如此一来，tmp[0...size) 中就保存了一部分 A 的值。
    // 然后从位置 0 开始检查 tmp，如果发现该位置的值和索引号不匹配，就说明找到了缺失的数了。
    // 注意上面的方案可以不使用 tmp 数组，直接在原始数组中操作，把每个数放到正确的位置。
    // 我们使用一种 "座位交换法" 来达到 in-place 的目的：
    // 从第一个位置开始，让座位上的乘客走到自己应该坐的位置，并让该位置的人坐到第一个位置。
    // 一直进行这样的操作，直到第一个位置的人坐到自己位置。不过有时候我们知道，有的人总喜欢逃票。
    // 因此终止条件就是，一旦发现第一个位置的人逃票（票号 <= 0，或 >= 最大座位号)，则终止交换。
    // 对第二到N个位置做相同的操作。

    // 0ms,6.3MB
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (0 < nums[i] && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return nums.size() + 1;
    }
};