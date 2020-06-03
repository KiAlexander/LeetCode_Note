// https://leetcode-cn.com/problems/trapping-rain-water/
class Solution {
public:
	// 对于vector中每个点，水有多高取决于这个点左侧和右侧墙壁的最大高度。
	// 第一个for循环找每个点的左侧最大高度，第二个for循环找每个点右侧的最大高度，
	// 循环中跳过最左侧(i=0)和最右侧点(i=vector.size()-1)的原因是这两个点由于没有左侧墙壁
	// 或右侧墙壁所以最大墙壁高度肯定是0，故在初始化vector的时候已经将其默认设置成0了。
	// 在得到所有点的左右墙壁最大高度后，木桶原理取左右墙壁较低的那个高度减去当前位置墙壁
	// 作为地面的高度就得到了这个位置上水的高度。然后将所有点的水高度相加即为解。
    // 0ms,6.9MB
    int trap(vector<int>& height) {
        int n = height.size();
		// left[i]表示i左边的最大值，right[i]表示i右边的最大值
		vector<int> left(n), right(n);
		for (int i = 1; i < n; i++) {
			left[i] = max(left[i - 1], height[i - 1]);
		}
		for (int i = n - 2; i >= 0; i--) {
			right[i] = max(right[i + 1], height[i + 1]);
		}
		int water = 0;
		for (int i = 1; i < n-1; i++) {
			int level = min(left[i], right[i]);
			water += max(0, level - height[i]);
		}
		return water;
    }
};