// https://leetcode-cn.com/problems/combination-sum/
class Solution {
public:
	// 回溯法
	// 12ms,7.4MB
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        combinationSumCore(res, candidates, target, tmp, 0, 0);
        return res;
    }
    void combinationSumCore(vector<vector<int>> &res, vector<int>& candidates, int target, vector<int>& tmp, int sum, int begin){
        if(sum == target){
            res.push_back(tmp);
        }else{
            for(int i=begin; i<candidates.size(); ++i){
                if(sum+candidates[i]<=target){
                    tmp.push_back(candidates[i]);
                    combinationSumCore(res, candidates, target, tmp, sum+candidates[i], i);
                    tmp.pop_back();
                }
            }
        }
    }
};