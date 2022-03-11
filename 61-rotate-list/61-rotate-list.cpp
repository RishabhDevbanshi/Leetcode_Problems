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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return  head;
        int len = 0;
        auto curr = head;
        ListNode *tail = nullptr;
        while(curr)
        {
            tail = curr;
            curr = curr->next;
            len++;
        }
        
        k %= len;
        
        if(k == 0)
            return head;
        
        int rem = len - k;
        
        curr = head;
        ListNode *prev = nullptr;
        
        while(rem-- > 0)
            prev = curr,curr = curr->next;
        
        prev->next = nullptr;
        tail->next = head;
        
        return curr;
    }
};