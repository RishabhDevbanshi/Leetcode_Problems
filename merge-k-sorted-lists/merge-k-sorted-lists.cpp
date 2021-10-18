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

#define pi pair<int,ListNode *>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode *newHead = new ListNode(0);
        ListNode *tail = newHead;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        for(int i=0;i<n;i++)
        {
            if(lists[i]) pq.push({lists[i]->val , lists[i]});
        }
        
        
        while(!pq.empty())
        {
            ListNode *node = pq.top().second;
            pq.pop();
            tail->next = node;
            tail = tail->next;
            
            if(node->next) pq.push({node->next->val,node->next});
        }
        
        
        
        
        
        return newHead->next;
    }
};