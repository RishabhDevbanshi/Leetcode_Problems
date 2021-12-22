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
    void reorderList(ListNode* head) {
        
        if(!head || !head->next || !head->next->next)
            return;
        
        stack<ListNode*> st;
        ListNode *ptr = head;
        
        int sz = 0;
        
        while(ptr)
        {
            sz++;
            st.push(ptr);
            ptr = ptr->next;
        }
        
        ListNode *res = head;
        
        for(int i=0;i<sz/2;i++)
        {
            ListNode *node = st.top(); st.pop();
            node->next = res->next;
            res->next = node;
            res = res->next->next;
        }
        
        
        res->next = nullptr;
        
        
    }
};