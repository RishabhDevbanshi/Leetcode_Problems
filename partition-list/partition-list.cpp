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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = NULL , *smallLast = NULL;
        ListNode* greatHead = NULL , *greatLast = NULL;
        
        ListNode *curr = head;
        while(curr)
        {
            int val = curr->val;
            if(val < x)
            {
                if(!smallHead) smallHead = smallLast = curr;
                else
                {
                    smallLast->next = curr;
                    smallLast = smallLast->next;
                }
            }
            else
            {
                if(!greatHead) greatHead = greatLast = curr;
                else
                {
                    greatLast->next = curr;
                    greatLast = greatLast->next;
                }
            }
            curr = curr->next;
        }
        
        
        if(smallHead == NULL and greatHead == NULL)
        {
            return NULL;
        }
        else if(smallHead == NULL)
        {
            greatLast->next = NULL;
            return greatHead;
        }
        else if(greatHead == NULL)
        {
            smallLast->next = NULL;
            return smallHead;
        }
        else 
        {
            smallLast->next = greatHead;
            greatLast->next = NULL;
            return smallHead;
        }
    }
};