class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;
        int last;
        for(int i=0;i<size(wall);i++)
        {
            int pre = 0;
            for(int j=0;j<size(wall[i]);j++)
            {
                pre += wall[i][j];   
                mp[pre]++;
            }
            last = pre;
        }
        
        int maxi = 0;
        
        for(auto it : mp)
        {
            if(it.first != last) maxi = max(maxi,it.second);
        }
            
            
        return size(wall) - maxi;
    }
};