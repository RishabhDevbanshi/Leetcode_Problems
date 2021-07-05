class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        int fact = 1;
        
        for(int i=1;i<n;i++)
        {
            fact = fact*i;
            arr.push_back(i);
        }
        arr.push_back(n);
        string ans = "";
        
        k = k-1;
        
        while(true)
        {
            int idx = k/fact;
            ans += to_string(arr[idx]);
            arr.erase(arr.begin() + idx);
            
            if(arr.size() == 0) break;
            
            k = k%fact;
            fact = fact/arr.size();
        }
        
        return ans;
        
    }
};