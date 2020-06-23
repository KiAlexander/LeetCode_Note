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
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return NULL;
        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i; //记住每个数的位置
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode * build(vector<int>& inorder, vector<int>& postorder, int inL, int inR, int pL, int pR){
        if (pL > pR) return NULL;
        TreeNode * root = new TreeNode(postorder[pR]);
        // cout << root->val << endl;
        int k = mp[postorder[pR]];
        root->left = build(inorder, postorder, inL, k - 1, pL, pL + k - inL - 1);
        root->right = build(inorder, postorder, k + 1, inR, pL + k - inL, pR - 1);
        return root;
    }
};