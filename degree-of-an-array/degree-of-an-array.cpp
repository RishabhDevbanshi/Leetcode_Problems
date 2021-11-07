struct util
{
    int freq , start , end;
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,util> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]) != mp.end())
            {
                mp[nums[i]].freq++;
                mp[nums[i]].end = i;
            }
            else
            {
                util a;
                a.freq = 1 , a.start = i , a.end = i;
                mp[nums[i]] = a;
            }
        }
        
        int ans = 0,mf=0;
        for(auto &[key,value] : mp)
        {
            // cout<<key<<" "<<value.freq<<" "<<value.start<<" "<<value.end<<"\n";
            if(value.freq > mf)
            {
                mf = value.freq;
                ans = value.end - value.start + 1;
            }
            else if(value.freq == mf)
            {
                ans = min(ans,value.end - value.start  +1);
            }
        }
        // cout<<mf;
        return ans;
    }
};