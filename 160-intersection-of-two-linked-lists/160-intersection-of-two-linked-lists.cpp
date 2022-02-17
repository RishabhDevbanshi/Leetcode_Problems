/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> st;
        auto tmp = headB;
        while(tmp)
        {
            st.insert(tmp);
            tmp = tmp->next;
        }
        
        tmp = headA;
        
        while(tmp)
        {
            if(st.count(tmp))
            {
                return tmp;
            }
            
            tmp = tmp->next;
        }
        
        return nullptr;
    }
};