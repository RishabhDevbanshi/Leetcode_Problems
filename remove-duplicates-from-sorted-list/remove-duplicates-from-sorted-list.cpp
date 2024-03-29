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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) 
            return head;
        ListNode *prev = head , *curr = head->next , *next;
        
        while(curr)
        {
            next = curr->next;
            if(curr->val == prev->val)
            {
                prev->next = curr->next;
                curr->next = NULL;
                curr = next;
            }
            else
            {
                prev = curr;
                curr = next;
            }
        }
        
        return head;
    }
};