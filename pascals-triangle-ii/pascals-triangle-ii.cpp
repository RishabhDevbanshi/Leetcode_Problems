class Solution {
    vector<int> recur(vector<int> &prev,vector<int> &arr,int A)
    {
        if(A==0) return prev;

        int n = prev.size() + 1;
        arr.resize(n,0);
        arr[0] = arr[n-1] = 1;
        for(int i=1;i<n-1;i++) arr[i] = prev[i-1] + prev[i];
        prev.clear();
        return recur(arr,prev,A-1);
    }
public:
    vector<int> getRow(int A) {
        vector<int> prev;
        vector<int> arr;
        prev.push_back(1);
        return recur(prev,arr,A);
    }
};