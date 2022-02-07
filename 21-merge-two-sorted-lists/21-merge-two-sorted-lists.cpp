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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *head = new ListNode();
        auto tail = head;
        
        while(list1 and list2)
        {
            if(list1->val < list2->val)
            {
                tail->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                tail->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            
            tail = tail->next;
        }
        
        while(list1)
        {
            tail->next = new ListNode(list1->val);
            list1 = list1->next;
            tail = tail->next;
        }
        
        while(list2)
        {
            tail->next = new ListNode(list2->val);
            list2 = list2->next;
            tail = tail->next;
        }
        
        return head->next;
    }
};