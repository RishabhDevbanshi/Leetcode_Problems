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
    int pairSum(ListNode* head) {
        unordered_map<int,int> mp;
        int idx=0;
        auto node = head;
        while(node)
        {
            mp[idx++] = node->val;
            node = node->next;
        }
        
        int res = 0;
        
        int n = size(mp);
        
        for(int i=0;i<n/2;i++)
        {
            res = max(res,mp[i] + mp[n-1-i]);
        }
        
        return res;
    }
};