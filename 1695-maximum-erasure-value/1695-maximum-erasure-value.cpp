class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;
        int ans = 0;
        
        for(int i=0,j=0,curr=0;j<n;j++)
        {
            while(st.find(arr[j]) != st.end())
            {
                st.erase(arr[i]);
                curr -= arr[i];
                i++;
            }
            st.insert(arr[j]);
            curr += arr[j];
            
            ans = max(ans,curr);
        }
        
        
        return ans;
    }
};