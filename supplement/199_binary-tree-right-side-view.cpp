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
// 使用层序遍历，并只保留每层最后一个节点的值
// 左右子树入队顺序调换
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            res.push_back(q.front()->val);
            while (size--)
            {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->right) q.push(temp->right);
                if (temp->left) q.push(temp->left);
            }
        }
        return res;
    }
};