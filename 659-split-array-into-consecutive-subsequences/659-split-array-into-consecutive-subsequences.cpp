class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,multiset<int>> mp;
        for(int i=0;i<size(nums);i++)
        {
            if(mp.find(nums[i]-1) != mp.end() and size(mp[nums[i]-1]))
            {
                int len = *mp[nums[i]-1].begin() ;
                mp[nums[i]-1].erase(mp[nums[i]-1].begin());
                mp[nums[i]].insert(len+1);
            }
            else mp[nums[i]].insert(1);
        }
        for(auto it : mp)
        {
            if(it.second.size() == 0) continue;
            if(*it.second.begin() < 3)
                return false;
        }
        
        return true;
    }
};