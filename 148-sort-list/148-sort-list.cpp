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
    
    ListNode *findMid(ListNode *head)
    {
        ListNode *fast = head , *slow = nullptr;
        while(fast and fast->next)
        {
            slow = slow ? slow->next : head;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode *merge(ListNode *a,ListNode *b)
    {
        ListNode *tmp = new ListNode();
        ListNode *tail = tmp;
        
        while(a and b)
        {
            if(a->val < b->val)
                tail->next = a , a = a->next;
            else tail->next = b , b = b->next;
            
            tail = tail->next;
        }
        
        tail->next = a ? a : b;
        
        return tmp->next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode *slow = findMid(head);
        
        ListNode *mid = slow->next;
        slow->next = nullptr;
        
        ListNode *a = sortList(head);
        ListNode *b = sortList(mid);
        
        return merge(a,b);
    }
};