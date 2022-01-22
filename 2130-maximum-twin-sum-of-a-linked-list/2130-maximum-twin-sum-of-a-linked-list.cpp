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
    
    void reverse(ListNode **head)
    {
        if(!head)
            return ;
        ListNode *prev = nullptr , *curr = *head , *next;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        *head = prev;
    }
    
public:
    int pairSum(ListNode* head) {
        
        ListNode *fast = head , *slow = head , *prev = nullptr;
        
        while(fast and fast->next)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        prev->next = nullptr;
        reverse(&slow);
        auto curr = head;
        
        int res = 0;
        while(slow)
        {
            res = max(res,slow->val + curr->val);
            curr = curr->next;
            slow = slow->next;
        }
        
        return res;
    }
};