/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	// 对于连续整数序列[left, right]中的一点i，若要生成以i为根节点的BST，则有如下规律：
	// 	1.i左边的序列可以作为左子树结点，且左儿子可能有多个，所以有vector<TreeNode *> left_nodes = generate(left, i - 1);；
	// 	2.i右边的序列可以作为右子树结点，同上所以有vector<TreeNode *> right_nodes = generate(i + 1, right);
	// 	3.产生的以当前i为根结点的BST（子）树有left_nodes.size() * right_nodes.size()个，遍历每种情况，即可生成以i为根节点的BST序列；
	// 	4.然后以for循环使得[left, right]中每个结点都能生成子树序列。
    vector<TreeNode *> generateTrees(int n) {
        if (n) return generate(1, n);
        else return vector<TreeNode *>{};
    }
    
    vector<TreeNode *> generate(int left, int right) {
        vector<TreeNode *> ans;
        if (left > right) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = left; i <= right; i++) {
            vector<TreeNode *> left_nodes = generate(left, i - 1);
            vector<TreeNode *> right_nodes = generate(i + 1, right);
            for (TreeNode *left_node : left_nodes) {
                for (TreeNode *right_node : right_nodes) {
                    TreeNode *t = new TreeNode(i);
                    t->left = left_node;
                    t->right = right_node;
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};