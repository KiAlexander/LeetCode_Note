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
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)    return true;
        return isMirror(root->left,root->right);
    }
    
    bool isMirror(TreeNode *p,TreeNode *q)          //递归函数
    {
        if(!p && !q)        return true;        //如果p,q均为NULL
        if(!p || !q)        return false;       //p,q只有一者为NULL

        return (p->val==q->val) && isMirror(p->left,q->right) && isMirror(p->right,q->left);        
    }

};