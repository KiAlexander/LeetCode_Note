// https://leetcode-cn.com/problems/3sum/
class Solution {
public:
    // 1.暴力双指针
    // 124ms,19.6MB
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 特判，对于数组长度 n，如果数组为 nullnull 或者数组长度小于 3，返回 []。
        // 对数组进行排序。
        // 遍历排序后数组：
        // 若 nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于 0，直接返回结果。
        // 对于重复元素：跳过，避免出现重复解
        // 令左指针 L=i+1，右指针 R=n-1，当 L<R 时，执行循环：
        // 当 nums[i]+nums[L]+nums[R]==0，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,R 移到下一位置，寻找新的解
        // 若和大于 0，说明 nums[R] 太大，R 左移
        // 若和小于 0，说明 nums[L] 太小，L 右移
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                return res;
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int L=i+1;
            int R=n-1;
            while(L<R){
                if(nums[i]+nums[L]+nums[R]==0){
                    res.push_back({nums[i],nums[L],nums[R]});
                    while(L<R and nums[L]==nums[L+1])
                        L=L+1;
                    while(L<R and nums[R]==nums[R-1])
                        R=R-1;
                    L=L+1;
                    R=R-1;
                }
                else if(nums[i]+nums[L]+nums[R]>0)
                    R=R-1;
                else
                    L=L+1;

            }

            
        }
        return res;
    }


    // 2.注意去重
    // 84ms,19.7MB
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if ((target = nums[i]) > 0) break;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] + target < 0) ++l;
                else if (nums[l] + nums[r] + target > 0) --r;
                else {
                    ans.push_back({target, nums[l], nums[r]});
                    ++l, --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
            }
        }
        return ans; 
    }

};