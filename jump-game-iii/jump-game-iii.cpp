class Solution {
    bool recur(vector<int> &arr,int idx,unordered_map<int,int> &mp)
    {
        if(idx < 0 or idx >= size(arr))
            return false;
        if(arr[idx] == -1)
            return false;
        
        if(arr[idx] == 0)
            return true;
        
        int val = arr[idx];
        arr[idx] = -1;
        
        return recur(arr,idx + val,mp) or recur(arr,idx - val,mp);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_map<int,int> mp;
        return recur(arr,start,mp);
    }
};