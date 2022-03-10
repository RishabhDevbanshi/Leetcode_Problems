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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode();
        
        int carry = 0;
        
        sum->val = (l1->val + l2->val)%10;
        carry = (l1->val + l2->val)/10;
        
        ListNode* res = sum;
        // sum = sum->next;
        
        l1 = l1->next; l2 = l2->next;
        
        while(l1 and l2)
        {
            int tot = l1->val + l2->val + carry;
            carry = tot/10;
            auto node = new ListNode(tot%10);
            sum->next = node;
            sum = sum->next;
            l1 = l1->next; l2 = l2->next;
        }
        
        while(l1)
        {
            int tot = carry + l1->val;
            carry = tot/10;
            auto node = new ListNode(tot%10);
            sum->next = node;
            sum = sum->next;
            l1 = l1->next;
        }
        
        while(l2)
        {
            int tot = carry + l2->val;
            carry = tot/10;
            auto node = new ListNode(tot%10);
            sum->next = node;
            sum = sum->next;
            l2 = l2->next;
        }
        
        if(carry)
        {
            ListNode* node = new ListNode(carry);
            sum->next = node;
            sum = sum->next;
        }
        
        
        return res;
    }
};