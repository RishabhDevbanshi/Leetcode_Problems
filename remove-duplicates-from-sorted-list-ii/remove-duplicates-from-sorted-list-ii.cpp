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
    ListNode* deleteDuplicates(ListNode* A) {
        if(!A || !A->next) return A;
        ListNode *curr = A;
        ListNode* newHead = new ListNode(-1);
        ListNode* tail = newHead;
        while(curr)
        {
            int val = curr->val;
            if(curr->next and curr->next->val == val)
            {
                while(curr and curr->val == val) curr = curr->next;
            }
            else
            {
                tail->next = curr;
                tail = tail->next;
                curr = curr->next;
            }
        }
        tail->next = NULL;
        return newHead->next;
    }
};