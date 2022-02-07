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
    
    ListNode *merge(ListNode *a,ListNode *b)
    {
        if(!a) return b;
        if(!b) return a;
        
        ListNode *head = nullptr;
        if(a->val < b->val)
        {
            head = a;
            a = a->next;
        }
        else
        {
            head = b;
            b = b->next;
        }
        
        ListNode *tail = head;
        
        while(a and b)
        {
            if(a->val < b->val)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            
            tail = tail->next;
        }
        
        if(a) 
            tail->next = a;
        else
            tail->next = b;
        
        return head;
    }
    
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head, *fast = head->next;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *mid = findMid(head);
        ListNode *right = mid->next;
        mid->next = NULL;
        // cout<<right->val<<"\n";
        return merge(sortList(head) , sortList(right));
    }
};