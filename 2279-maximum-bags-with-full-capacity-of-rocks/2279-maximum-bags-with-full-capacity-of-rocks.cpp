class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> emp(size(rocks));
        for(int i=0;i<size(rocks);i++)
            emp[i] = capacity[i] - rocks[i];
        
        sort(emp.begin(),emp.end());
        int cnt = 0;
        
        for(auto &val : emp)
        {
            if(additionalRocks < val)
                break;
            additionalRocks -= val;
            cnt++;
        }
        
        
        return cnt;
    }
};