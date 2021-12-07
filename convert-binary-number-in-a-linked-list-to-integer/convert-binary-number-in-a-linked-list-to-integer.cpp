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
    int getDecimalValue(ListNode* head) {
        int len = 0;
        int idx = 0 , res = 0;
        ListNode *temp = head;
        
        while(temp) len++ , temp = temp->next;
        
        temp = head , idx = len-1;
        
        while(temp)
        {
            int val = (temp->val) * (1 << idx);
            cout<<val<<" ";
            temp = temp->next; idx--;
            // res *= 10;
            res += val;
        }
        
        return res;
    }
};