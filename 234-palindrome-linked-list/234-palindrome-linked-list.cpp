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
    
    ListNode *reverse(ListNode *head)
    {
        if(!head || !head->next)
            return  head;
        
        ListNode *curr = head , *prev = nullptr, *next;
        
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        
        ListNode *slow = nullptr , *fast = head;
        int cnt = 0;
        while(fast and fast->next)
        {
            cnt++;
            fast = fast->next->next;
            slow = slow ? slow->next : head;
        }
        
        ListNode *node = slow->next;
        slow->next = nullptr;
        
        node = reverse(node);
        
        auto fr = head;
        
        // int x = 0;
        
        while(cnt-- > 0)
        {
            if(fr->val != node->val)
                return false;
            fr = fr->next;
            node = node->next;
        }
        
        // cout<<slow->val<<"\n";
        
        return  true;
    }
};