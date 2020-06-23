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
   int helper(TreeNode* root, int sum){
        if(!root)
            return 0;
        else if (!root->left && !root->right)
            return 10*sum + root->val;
        return helper(root->left, 10*sum + root->val) + 
            helper(root->right, 10*sum + root->val);
    }
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};