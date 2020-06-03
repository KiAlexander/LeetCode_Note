// https://leetcode-cn.com/problems/subsets/
class Solution {
public:
	// 位运算
	// 子集，实际上就是考虑每个数字是否出现在集合中。一个数出现与不出现共两种情况，
	// 因此 n 个数的子集共有 2^n 个。把这 n 个数对应到 n 位二进制上，每个数出现与否体现为二进制位为 0 或 1。
	// 因此，在 [0,2^n) 之间的每一个数的二进制信息就能唯一确定一个子集。
	// 比如对于集合 [1,2,3], 001 就表示只取第 1 个元素，构成集合为 {1}。101 就表示只取 1 和 3，表集合 {1,3}。
	// 4ms,7.2MB
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back({});
        int size=nums.size();
        int subsize=pow(2,size);
        int hash=1;
        while(hash<subsize){
            vector<int> temp;
            for(int k=0;k<size;k++) {
                int a=1<<k;
                if(a&hash) {
                    temp.push_back(nums[k]);
                }
            }
            ret.push_back(temp);
            hash++;
        }
        return ret;
    }

    // dfs
    // 8ms,7.4MB
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        getSubsets(nums,0,vec);
        return res;
    }
    void getSubsets(vector<int> nums,int begin,vector<int> vec){
        res.push_back(vec);
        for(int i=begin;i<nums.size();i++){
            vec.push_back(nums[i]);
            getSubsets(nums,i+1,vec);
            vec.pop_back();
        }
    }

};
