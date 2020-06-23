/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    // 用两个指针，一块一慢，快的每次走两步，慢的每次走一步，这样当快指针遍历结束时，
    // 慢指针指向的也就是链表的中间位置。这时候把中间位置的结点的值作为二叉搜索树当前结点的值
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root;       
        if(!head)
            return nullptr;
        
        if(!head->next){
            root = new TreeNode(head->val);
            return root;
        }        
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        while(prev->next != slow)
            prev = prev->next;      
        root = new TreeNode(slow->val);
        ListNode* headRight = slow->next;
        prev->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(headRight);
        
        return root;
        
    } 

};