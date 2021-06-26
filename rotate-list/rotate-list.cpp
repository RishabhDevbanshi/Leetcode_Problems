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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        ListNode *tail , *newHead;
        tail = newHead = head;
        
        int len = 1;
        
        while(tail->next)
        {
            tail = tail->next;
            ++len;
        }
        
        tail->next = head;
        
        k = k%len;
        
        if(k)
        {
            for(int i=0;i<len-k;i++)
            {
                tail = tail->next;
            }
            // cout<<tail->val<<" ";
        }
        
        newHead = tail->next;
        tail->next = NULL;
        
        return newHead;
        
    }
};