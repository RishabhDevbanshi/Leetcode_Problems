class Solution {
    vector<vector<int>> v;
    vector<int> util(int n)
    {
        vector<int> arr;
        if(n == 1)
        {
            arr.push_back(1);
            v.push_back(arr);
            return arr;
        }
        
        vector<int> ans = util(n-1);
        
        vector<int> toRet;
        toRet.push_back(ans[0]);
        for(int i=1;i<ans.size();i++) toRet.push_back(ans[i-1] + ans[i]);
        if(ans.size() >= 1) toRet.push_back(ans[ans.size()-1]);
        
        v.push_back(toRet);
        
        return toRet;
    }
public:
    vector<vector<int>> generate(int numRows) {
        v.clear();
        util(numRows);
        
        return v;
    }
};