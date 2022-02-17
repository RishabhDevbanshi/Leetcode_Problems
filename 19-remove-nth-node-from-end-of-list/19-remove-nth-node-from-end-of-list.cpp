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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *ah = head;
        while(cnt<n and ah)
        {
            ah = ah->next;
            cnt++;
        }
        
        ListNode *prev = nullptr , *curr = head;
        
        while(ah)
        {
            ah = ah->next;
            prev = curr;
            curr = curr->next;
        }
        
        if(!prev)
        {
            auto node = head->next;
            head->next = nullptr;
            delete head;
            return node;
        }
        
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
        
        return head;
        
    }
};