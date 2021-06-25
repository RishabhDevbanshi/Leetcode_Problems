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
    ListNode* findMiddle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while(fast->next and fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode *head)
    {
        ListNode *curr = head , *prev = NULL , *next;
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
        if(!head or !head->next) return true;
        
        ListNode *mid = findMiddle(head);
        
        // cout<<mid->val<<"\n";
        
        mid->next = reverse(mid->next);
        mid = mid->next;
        
        while(mid)
        {
            if(head->val != mid->val) return false;
            head = head->next;
            mid = mid->next;
        }
        
        return true;
    }
};



