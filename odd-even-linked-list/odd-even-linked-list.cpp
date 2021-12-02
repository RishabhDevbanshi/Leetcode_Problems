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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head; 
        int cnt = 1,idx = 2;
        ListNode *temp = head->next,*prev = head,*next;
        while(temp)
        {
            next = temp->next;
            if(idx%2 != 0)
            {
                prev->next = next;
                temp->next = head;
                head = temp;
                temp = next;
                cnt++;
            }
            else
            {
                prev = temp;
                temp = next;
            }
            idx++;
        }
        ListNode *start = head;
        temp = head , prev = NULL , next = NULL;
        while(temp and cnt-- > 0)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        start->next = temp;
        return prev;
    }
};