class Solution {
    
    void recur(vector<int> &cand,int tar,int idx,vector<int> &arr,vector<vector<int>> &res)
    {
        if(idx == size(cand))
        {
            if(tar == 0) res.push_back(arr);
            return;
        }
        
        if(cand[idx] <= tar)
        {
            arr.push_back(cand[idx]);
            recur(cand,tar - cand[idx],idx,arr,res);
            arr.pop_back();
        }
        
        recur(cand,tar,idx+1,arr,res);
    }
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(),candidates.end());
        vector<int> arr;
        vector<vector<int>> res;
        
        recur(candidates,target,0,arr,res);
        
        return res;
    }
};