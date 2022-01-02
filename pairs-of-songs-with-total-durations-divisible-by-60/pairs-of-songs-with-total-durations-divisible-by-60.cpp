class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> mp;
        int cnt = 0;
        
        // for(int i=0;i<size(time);i++)
        // {
        //     for(int j=i+1;j<size(time);j++)
        //     {
        //         int sum = time[i] + time[j];
        //         // if(sum%60 == 0) cout<<time[i]<<" "<<time[j]<<"\n";
        //     }
        // }
        
        for(auto &ele : time)
        {
            int rem = ele%60;
            // cout<<rem<<" ";
            int x = 60 - rem;
            
            if(x == 60) x = 0;
            
            if(mp.count(x))
            {
                cnt += mp[x];
            }
            
            mp[ele%60]++;
        }
        
        return cnt;
    }
};