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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head || !head->next)
            return head;
        
        // cout<<head->val<<"\n";
        
        int cnt = 1;
        auto node = head;
        
        while(node and cnt < k)
        {
            cnt++;
            node = node->next;
        }
        // cout<<head->val<<" ";
        // cout<<cnt<<"\n";
        
        if(!node)
            return head;
        
        auto nxt = node ? node->next : nullptr;
        
        if(node) node->next = nullptr;
        
        nxt = reverseKGroup(nxt,k);
        
        ListNode *curr = head , *prev = nullptr , *next;
        
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head->next = nxt;
        
        
        return prev;
    }
};