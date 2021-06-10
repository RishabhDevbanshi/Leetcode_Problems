/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *tor = head, *hare = head;
        
        while(hare and hare->next)
        {
            tor = tor->next;
            hare = hare->next->next;
            
            if(tor == hare) return true;
        }
        
        return false;
    }
};