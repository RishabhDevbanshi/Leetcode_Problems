/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return nullptr;
        
        ListNode *newHead = removeElements(head->next,val);
        
        if(!newHead)
        {
            head->next = nullptr;
            return head->val == val ? nullptr : head;
        }
        
        if(head->val == val)
        {
            return newHead;
        }
        
        head->next = newHead;
        
        return head;
    }
};