class Solution {
public:
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>>res;
    //     vector<int>temp=nums;
    //     do{
    //         res.push_back(temp);
    //         next_permutation(temp.begin(),temp.end());
    //     }while(temp!=nums);
    //     return res;
    // }
    // --------------------------------------------------
    //  vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>>res;
    //     vector<int>vis(nums.size(),0);
    //     dfs(res,{},nums,vis);
    //     return res;
    // }
    // void dfs(vector<vector<int>>& res,vector<int> path,vector<int>& nums,vector<int>& vis){
    //     if(path.size()==nums.size()){
    //         res.push_back(path);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(vis[i]) continue;
    //         vis[i]=1;
    //         path.push_back(nums[i]);
    //         dfs(res,path,nums,vis);
    //         path.pop_back();
    //         vis[i]=0;
    //     }
    // }
    // --------------------------------------------------------
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }

};