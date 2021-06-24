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
        if(!head) return head;
        ListNode *prev = NULL, *slow = head , *fast = head;
        
        int temp = n;
        while(temp>0 and fast)
        {
            fast = fast->next;
            temp--;
        }
        
        if(temp) return head;
        
        while(fast)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        if(slow == head)
        {
            auto temp = head->next;
            delete head;
            return temp;
        }
        
        prev->next = slow->next;
        slow->next = NULL;
        delete slow;
        
        return head;
    }
};