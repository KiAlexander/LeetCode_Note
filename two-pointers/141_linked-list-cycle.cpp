// https://leetcode-cn.com/problems/linked-list-cycle/
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
	// 快慢指针
	// 12ms,7.5MB
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)  return false;
        ListNode *fast=head->next;
        ListNode *slow=head;
        while(fast!=slow){
         if(fast->next==NULL||fast->next->next==NULL)return false;
         fast= fast->next->next;
         slow=slow->next;
        }
        return true;
    }
};