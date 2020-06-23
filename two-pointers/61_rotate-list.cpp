// https://leetcode-cn.com/problems/rotate-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	// 先遍历求得链表总长度count，同时将链表首尾相连；
	// 再找到原链表的倒数第k+1个节点，该节点的next就是新链表的头结点。
	// 12ms,7.2MB
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *pst = head;
        ListNode *last = NULL;
        int count = 0;
        while(pst != NULL){
            ++count;
            last = pst;
            pst = pst->next; 
        }
        if(count == 0){
            return head;
        }
        int actual = k % count;
        last -> next = head;
        pst = head;
        for(int i = 0;i < count - actual - 1;++i){
            pst = pst->next;
        }
        head = pst->next;
        pst->next = NULL;
        return head;
    }
};