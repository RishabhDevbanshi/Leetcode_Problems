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
    ListNode* iterativeReverse(ListNode* head)
    {
        ListNode *prev = NULL, *curr = head , *next;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* recursiveReverse(ListNode* head)
    {
        if(!head or !head->next) return head;
        
        ListNode* newHead = recursiveReverse(head->next);
        
        head->next->next = head;
        
        head->next = NULL;
        
        return newHead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        // return iterativeReverse(head);
        return recursiveReverse(head);
    }
};