class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        
        vector<int> pos;
        
        int maxi = 0;
        
        auto check = [&](){
            int cnt = 0;
              for(auto &v : mat)
              {
                  int sum = accumulate(v.begin(),v.end(),0);
                  for(auto &val : pos)
                      sum -= v[val];
                  
                  cnt += sum==0;
              }
            
            return cnt;
        };
        
        function<void(int,int)> dfs = [&](int idx,int sel){
          if(sel == cols)
          {
                int x = check();
                maxi = max(maxi,x);
              return;
          }
        
        if(idx == size(mat[0]))
            return;
            
            dfs(idx+1,sel);
            pos.push_back(idx);
            dfs(idx+1,sel+1);
            pos.pop_back();
        };
        
        dfs(0,0);
        
        return maxi;   
    }
};