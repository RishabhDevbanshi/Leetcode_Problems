class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxHeap;
        
        int n = arr.size();
        
        for(int i=0;i<n;i++)
        {
            maxHeap.push( { abs(arr[i] - x), arr[i] } );
            
            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        
        vector<int> ans;
        while(!maxHeap.empty())
        {
            ans.push_back(maxHeap.top().second);
            
            maxHeap.pop();
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};