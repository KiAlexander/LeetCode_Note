// https://leetcode-cn.com/problems/sort-colors
class Solution {
public:
	// 0ms,8.5MB
    void sortColors(vector<int>& nums) {
        int _0 = 0;                 // 定义出现红色次数
        int _1 = 0;                 // 定义出现白色次数
        int _2 = 0;                 // 定义出现蓝色次数
        //统计每个频率出现的次数
        for(int i = 0; i < nums.size(); i++) {
            switch(nums[i]) {
                case 0:
                    _0++;
                    break;
                case 1:
                    _1++;
                    break;
                case 2:
                    _2++;
                    break;                    
            }
        }
        nums.clear();   //原来的清空数据
        // 红色赋值
        for(int i = 0; i < _0; i++) {
            nums.push_back(0);
        }
        // 白色赋值
        for(int i = 0; i < _1; i++) {
            nums.push_back(1);
        }
        // 蓝色赋值
        for(int i = 0; i < _2; i++) {
            nums.push_back(2);
        }                
    }
};