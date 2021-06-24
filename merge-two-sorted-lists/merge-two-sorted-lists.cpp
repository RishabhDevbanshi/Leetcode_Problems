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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* ans;
        
        ListNode *t1 = l1 , *t2 = l2;
        
        if(t1->val < t2->val) {ans = new ListNode(t1->val); t1 = t1->next;}
        else {ans = new ListNode(t2->val); t2 = t2->next;}
        
        ListNode *res = ans;
        
        while(t1 and t2)
        {
            ListNode *node = new ListNode();
            
            if(t1->val < t2->val)
            {
                node->val = t1->val;
                t1 = t1->next;
            }
            else
            {
                node->val = t2->val;
                t2 = t2->next;
            }
            
            
            ans->next = node;
            ans = ans->next;
        }
        
        while(t1)
        {
            ListNode* node = new ListNode(t1->val);
            ans->next = node;
            ans = ans->next;
            
            t1 = t1->next;
        }
        
        while(t2)
        {
            ListNode* node = new ListNode(t2->val);
            ans->next = node;
            ans = ans->next;
            
            t2 = t2->next;
        }
        
        
        return res;
    }
};