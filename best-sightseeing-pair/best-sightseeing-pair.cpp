class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n = size(values);
        
        if(n == 1)
            return 0;
        
        vector<int> pre(size(values));
        pre[0] = values[0];
        for(int i=1;i<n;i++)
        {
            pre[i] = max(pre[i-1] , values[i] + i); 
        }
        
        int res = INT_MIN;
        
        for(int i=1;i<n;i++)
        {
            int val = values[i] - i + pre[i-1];
            res = max(res,val);
        }
        
        
        return res;
    }
};