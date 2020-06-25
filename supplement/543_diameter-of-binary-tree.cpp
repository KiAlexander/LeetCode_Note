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
// 将二叉树的直径转换为：二叉树的 每个节点的左右子树的高度和 的最大值。
    int max_depth=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int temp=check_depth(root);
        return max_depth;
    }
    int check_depth(TreeNode *root)
    {
        if(!root)return 0;
        int left_length = check_depth(root->left);
        int right_length = check_depth(root->right);
        if((left_length+right_length)>max_depth)max_depth=left_length+right_length;
        return max(left_length,right_length)+1;
    }