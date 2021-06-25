/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int size(ListNode* head)
    {
        int cnt = 0;
        while(head != NULL) {head = head->next; cnt++;}
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA) return headB;
        if(!headB) return headA;
        
        auto a = headA , b = headB;
        int szA = size(a) , szB = size(b);
        
        if(szA > szB)
        {
            while(szA > szB) {a = a->next; szA--;}
        }
        else if(szB > szA) while(szB > szA) {b = b->next; szB--;}
        
        while(a and b)
        {
            if(a == b) return a;
            // cout<<a->val<<" "<<b->val<<" ";
            a = a->next;
            b = b->next;
        }
        
        return NULL;
        
    }
};