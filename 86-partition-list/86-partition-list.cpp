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
        ListNode *small_head = new ListNode(-1);
        ListNode *big_head = new ListNode(-1);
        ListNode *small_tail = small_head , *big_tail = big_head;
        
        ListNode *curr = head;
        while(curr)
        {
            if(curr->val < x)
            {
                small_tail->next = new ListNode(curr->val);
                small_tail = small_tail->next;
            }
            else
            {
                big_tail->next = new ListNode(curr->val);
                big_tail = big_tail->next;
            }
            
            curr = curr->next;
        }
        
        if(!big_head->next and !small_head->next)
        {
            return nullptr;
        }
        else if(!big_head->next)
        {
            return small_head->next;
        }
        else if(!small_head->next)
        {
            return big_head->next;
        }
        else
        {
            small_tail->next = big_head->next;
            return small_head->next;
        }
        
        
    }
};