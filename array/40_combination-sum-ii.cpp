// https://leetcode-cn.com/problems/combination-sum-ii/
class Solution {
public:
	// h4ms,7.2MB
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combinationSumCore(res, candidates, target, tmp, 0, 0);
        return res;
    }
    void combinationSumCore(vector<vector<int>> &res, vector<int>& candidates, int target, vector<int>& tmp, int sum, int begin){
        if(sum == target){
            res.push_back(tmp);
        }else{
            for(int i=begin; i<candidates.size(); ++i){
                if(sum+candidates[i]<=target){
                    if(i!=begin && candidates[i]==candidates[i-1]) //去重
                        continue;
                    tmp.push_back(candidates[i]);
                    combinationSumCore(res, candidates, target, tmp, sum+candidates[i], i+1);
                    tmp.pop_back();
                }
                else //剪枝
                    break;
            }
        }
    }
};