class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        string str = "";
        
        vector<int> res;
        
        function<void(int,int)> dfs = [&](int idx,int prev){
            if(idx == n)
            {
                res.push_back(stoi(str));
                return;
            }
            if(prev - k >= 0)
            {
                str += to_string(prev-k);
                dfs(idx+1,prev-k);
                str.pop_back();
            }
            
            if(prev + k  != prev - k and prev + k < 10)
            {
                str += to_string(prev+k);
                dfs(idx+1,prev+k);
                str.pop_back();
            }
        };
        
        for(int i=1;i<10;i++)
        {
            str += to_string(i);
            dfs(1,i);
            str.pop_back();
        }
        
        
        return res;
    }
};