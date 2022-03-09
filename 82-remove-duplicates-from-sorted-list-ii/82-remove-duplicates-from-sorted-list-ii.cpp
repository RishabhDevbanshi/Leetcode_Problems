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
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        
        ListNode *curr = head;
        
        int prev = -1000;
        
        while(curr)
        {
            if(curr->val == prev)
                curr = curr->next;
            else if(curr->next and curr->val == curr->next->val)
                prev = curr->val , curr = curr->next;
            else
                tail->next = new ListNode(curr->val) , tail = tail->next ,prev = curr->val, curr = curr->next;
        }
        
        return dummy->next;
    }
};