class Solution {
    int recur(vector<int> &arr,int n,int left,int right,int b,map<string,int> &mp)
    {
        if(b == 0) return 0;
        string key = to_string(b) + "," + to_string(left) + "," + to_string(right) + ".";
        
        if(mp.find(key) != mp.end())
                return mp[key];
        
        int l = INT_MIN , r = INT_MIN;
        if(left < n) l = arr[left] + recur(arr,n,left+1,right,b-1,mp);
        if(right >= 0) r = arr[right] + recur(arr,n,left,right-1,b-1,mp);

        return mp[key] = max(l,r);
    }
    
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int res = 0;
        for(int i=0;i<k;i++) res += arr[i];
        int curr = res, j = n-1;
        
        for(int i=k-1;i>=0;i--)
        {
            curr += arr[j] - arr[i];
            res = max(curr,res);
            j--;
        }
        
        return res;
    }
};