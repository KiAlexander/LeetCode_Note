class Solution {
public:
    //12ms,97%
    vector<vector<int>> combine(int n, int k) {
        vector<int> map(n,0);
        vector<vector<int>> res;
        for(int i=0;i<k;i++)
            map[i]=1;
        vector<int> tmp;
        do
        {
            for(int i=0;i<n;i++)
                if(map[i])  tmp.push_back(i+1);
            res.push_back(tmp);
            tmp.clear();
        }while(prev_permutation(map.begin(),map.end()));
        return res;
    }
    
// //44ms,62.56%
// public:
//     vector<vector<int>> combine(int n, int k) {
//         dfs(temp,n,k,0);
//         return res;
//     }
// private:
//     vector<vector<int>> res;
//     vector<int> temp;
//     void dfs(vector<int>& temp,int n,int k,int x){
//         if(temp.size()==k){
//             res.push_back(temp);
//             return;
//         }
//         for(int i=x+1;i<=n;i++){
//             temp.push_back(i);
//             dfs(temp,n,k,i);
//             temp.pop_back();
//         }
//     }
};