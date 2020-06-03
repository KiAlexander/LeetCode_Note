// https://leetcode-cn.com/problems/4sum/
class Solution {
public:
    // 1
	// 84ms,7.4MB
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int begin = j + 1;
                int end = (int) nums.size() - 1;
                while (begin < end) {
                    int sum = nums[i] + nums[j] + nums[begin] + nums[end];
                    if (sum > target) {
                        end --;
                    } else if (sum < target) {
                        begin ++;
                    } else {
                        bool flag = false;
                        for (const vector<int> & r: result) {
                            if (nums[i] == r[0] && nums[j] == r[1] && nums[begin] == r[2] && nums[end] == r[3]) {
                                flag = true;
                            }
                        }
                        if (! flag) {
                            result.push_back({nums[i], nums[j], nums[begin], nums[end]});
                        }
                        begin ++;
                        end --;
                    }
                }
            }
        }
        return result;
    }

    // 2.
    // 8ms,7.8MB
    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
         vector<vector<int>>  ret;
        int len =nums.size();
        if (len<4) return ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-3;i++){
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
                break;
            if (nums[i] + nums[len-1] + nums[len-2] + nums[len-3] < target)
                continue;
            for (int j=i+1;j<len-2;j++){
                  if (j-i > 1 && nums[j] == nums[j-1])
                continue;
                    if (nums[i] + nums[j+1] + nums[j+2] + nums[j] > target)
                break;
                  if (nums[i] + nums[len-1] + nums[len-2] + nums[j] < target)
                continue;
                int  left = j + 1;
                int right = len - 1;
                while (left < right){
                   int tmp = nums[i] + nums[j] + nums[left] + nums[right];
                    if (tmp == target){
                    vector<int> vec;
                    vec.push_back(nums[i]);
                     vec.push_back(nums[j]);
                      vec.push_back(nums[left]);
                       vec.push_back(nums[right]);
                   
                        ret.push_back(vec);
                    
                        while (left < right && nums[left] == nums[left+1])
                            left++;
                        while (left < right && nums[right] == nums[right-1])
                            right--;
                        left += 1;
                        right -= 1;
                    }
                    else if (tmp > target)
                        right--;
                    else
                        left++;
                }
            }
        }
        return ret;
    }

};