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
    // bool isBalanced(TreeNode* root) {
    //     if(root==NULL) return true;
    //     else if(root->left==NULL&&root->right==NULL) return true;
    //     else if(abs(height(root->left)-height(root->right))>1) return false;
    //     else{
    //         return isBalanced(root->left)&&isBalanced(root->right);
    //     }
    // }
    // int height(TreeNode* root)
    // {
    //     if(root==NULL) return 0;
    //     return max(height(root->left),height(root->right))+1;

    // }

    int depth(TreeNode* root)   //此节点的最大深度
    {
        if(root == NULL) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return abs(depth(root->right)-depth(root->left))<2 && isBalanced(root->left) && isBalanced(root->right);
    }
};