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
    ListNode* swapNodes(ListNode* head, int k) {
        int temp=k-1;
        ListNode* base1=head;
        while(temp--)
        {
            base1=base1->next;
        }
        int len=0;
        ListNode* base=head;
        while(base)
        {
            base=base->next;
            len++;
        }
        temp=len-k;
        ListNode* base2=head;
        while(temp--)
        {
            base2=base2->next;
        }
        cout<<base2->val<<endl;
        swap(base1->val,base2->val);
        return head;
    }
};