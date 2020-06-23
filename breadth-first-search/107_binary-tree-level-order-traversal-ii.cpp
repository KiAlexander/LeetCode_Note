/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //非递归
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         vector<vector<int>> last;
         queue<TreeNode *> Queue;//层遍历所需要的队列
         if(root==nullptr)return last;
         Queue.push(root);
         while(!Queue.empty())
         {
             ector<int> mid;
             int size=Queue.size();
             for(int i=0;i<size;i++)
             {
                 TreeNode *front=Queue.front();
                 mid.push_back(front->val);
                 Queue.pop();
                 if(front->left)Queue.push(front->left);
                 if(front->right)Queue.push(front->right);
             }
             last.push_back(mid);
         }
         reverse(last.begin(),last.end());
         return last;
    }
    //递归
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n = getDep(root);
        vector<vector<int>> ans(n, vector<int>());
        dfs(root, 0, ans, n - 1);
        return ans;
    }
    void dfs(TreeNode *root, int depth, vector<vector<int>>& ans, int n) {
        if (root == NULL) return ;
        ans[n - depth].push_back(root->val); // 倒着装 n - depth
        dfs(root->left, depth + 1, ans, n);
        dfs(root->right, depth + 1, ans, n);
    }
    int getDep(TreeNode *root) { // 求树的高度
        if (root == NULL) return 0;
        return max(getDep(root->left), getDep(root->right)) + 1;
    }

};