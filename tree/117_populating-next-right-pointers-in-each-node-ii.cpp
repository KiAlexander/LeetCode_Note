/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
    void dfs(Node* &root) {
        if (!root || (!root->left && !root->right))
            return;
        if (root->left && root->right) {
            root->left->next = root->right;
        }
        Node* cur = root->right ? root->right : root->left;
        Node* temp = root->next;
        while (temp) {
            if (temp->left) {
                cur->next = temp->left;
                break;
            } else if (temp->right) {
                cur->next = temp->right;
                break;
            }
            temp = temp->next;
        }
        // 先确保 root.right 下的节点的已完全连接，因 root.left 下的节点的连接
        // 需要 root.left.next 下的节点的信息，若 root.right 下的节点未完全连
        // 接（即先对 root.left 递归），则 root.left.next 下的信息链不完整，将
        // 返回错误的信息。可能出现的错误情况如下图所示。此时，底层最左边节点将无
        // 法获得正确的 next 信息：
        //                  o root
        //                 / \
        //     root.left  o —— o  root.right
        //               /    / \
        //              o —— o   o
        //             /        / \
        //            o        o   o
        dfs(root->right);
        dfs(root->left);
    }
};