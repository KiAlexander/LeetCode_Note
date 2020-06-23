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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            int len = queue.size();
            vector<int> tmp;
            for(int i = 0; i < len; i++){
                TreeNode* node = queue.front();
                queue.pop();
                tmp.push_back(node->val);
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
        
    }

    // 递归
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelsearch(root,0,res);
        return res;
    }
    void levelsearch(TreeNode* root,int level,vector<vector<int>> &res){
        if (!root) return ;
        if (level >= res.size())
            res.push_back(vector<int> {});
        res[level].push_back(root->val);
        levelsearch(root->left,level+1,res);
        levelsearch(root->right,level+1,res);
    }
};