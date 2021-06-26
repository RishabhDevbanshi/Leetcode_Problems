/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    bool checkCycle(ListNode *head)
    {
        ListNode *tor = head , *hare = head;
        while(hare and hare->next)
        {
            hare = hare->next->next;
            tor = tor->next;
            
            if(hare == tor) return true;
        }
        
        return false;
    }
    
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head or !head->next or !checkCycle(head)) return NULL;
        
        ListNode *tor = head , *hare = head;
        
        while(hare and hare->next)
        {
            hare = hare->next->next;
            tor = tor->next;
            
            if(hare == tor) break;
        }
        
        hare = head;
        
        if(tor == hare) return hare;
        
        while(hare)
        {
            tor = tor->next;
            hare = hare->next;
            
            if(tor == hare) return hare;
        }
        
        return NULL;
        
    }
};