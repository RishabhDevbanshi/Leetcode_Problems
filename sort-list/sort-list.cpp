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
        ListNode *slow = NULL , *fast = head;
        while(fast and fast->next)
        {
            if(!slow) slow = head;
            else slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        
        return mid;
    }
    
    ListNode *merge(ListNode *head1 , ListNode *head2)
    {
        ListNode *newHead = new ListNode(-1);
        ListNode *tail = newHead;
        
        while(head1 and head2)
        {
            if(head1->val < head2->val)
            {
                tail->next = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head2;
                head2 = head2->next;
            }
            
            tail = tail->next;
        }
        
        if(head1) tail->next = head1;
        else tail->next = head2;
        return newHead->next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *mid = findMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        
        return merge(left,right);
    }
};