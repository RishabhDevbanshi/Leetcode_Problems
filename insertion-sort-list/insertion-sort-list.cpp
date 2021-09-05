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
    ListNode *insert(ListNode *head,int val)
    {
        ListNode *node = new ListNode(val);
        if(!head) return node;
        else if(head->val > node->val)
        {
            node->next = head;
            // auto tmp = node;
            // while(tmp) {cout<<tmp->val<<" "; tmp = tmp->next;}
            return node;
        }
        
        ListNode *prev = head , *curr = head->next , *next;
        
        while(curr)
        {
            next = curr->next;
            if(curr->val > val)
            {
                prev->next = node;
                node->next = curr;
                return  head;
            }
            prev = curr;
            curr = next;
        }
        
        prev->next = node;
        return head;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newHead = NULL;
        ListNode *curr = head;
        while(curr)
        {
            newHead = insert(newHead,curr->val);
            auto tmp = newHead;
            // while(tmp) {cout<<tmp->val<<" "; tmp = tmp->next;}
            // cout<<"\n";
            curr = curr->next;
        }
        
        return newHead;
    }
};