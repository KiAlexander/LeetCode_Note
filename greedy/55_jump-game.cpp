class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 1; // 最右能跳到哪里
        for (int i = 0; i < reach && reach < nums.size(); ++i)
            reach = max(reach, i + 1 + nums[i]);
        return reach >= nums.size();
    }
};