class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        
        vector<vector<int>> res;
        vector<int> tmp;
        
        function<void(int,int,int)> fun = [&](int idx,int kk,int nn){
            if(kk == 0)
            {
                if(nn == 0)
                    res.push_back(tmp);
                
                return;
            }
            
            if(idx == size(arr))
                return;
            
            fun(idx+1,kk,nn);
            
            tmp.push_back(arr[idx]);
            
            fun(idx+1,kk-1,nn - arr[idx]);
            
            tmp.pop_back();
        };
        
        fun(0,k,n);
        
        return res;
    }
};