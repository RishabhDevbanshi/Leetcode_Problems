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

struct myCompare
{
    bool operator() (ListNode *a,ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *,vector<ListNode *>,myCompare> pq;
        for(auto &head : lists)
        {
            if(head)
                pq.push(head);
        }
        
        ListNode *newHead = new ListNode(-1);
        ListNode *tail = newHead;
        
        while(!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            
            // cout<<node->val<<" ";
            
            tail->next = node;
            tail = tail->next;
            
            if(node->next)
                pq.push(node->next);
        }
        
        // cout<<"\n";
        
        return newHead->next;
    }
};