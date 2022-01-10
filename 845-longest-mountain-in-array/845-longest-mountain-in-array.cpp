class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = size(arr);
        int res = 0;
        
        int idx = 0;
        while(idx < size(arr)-1)
        {
            if(arr[idx]<arr[idx+1])
            {
                bool peak = false , valley = false;
                int start = idx;
                
                while(idx<n-1 and arr[idx]<arr[idx+1])
                {
                    peak = true , idx++;
                }
                while(idx<n-1 and arr[idx]>arr[idx+1])
                {
                    valley = true , idx++;
                }
                
                if(peak and valley) res = max(res,idx-start+1);
            }
            else idx++;
        }
        
        
        return res;
        
    }
};