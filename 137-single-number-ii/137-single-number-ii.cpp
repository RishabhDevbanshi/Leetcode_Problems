class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        string str = "";
        
        for(int i=31;i>=0;i--)
        {
            int cnt = 0;
            // cout<<i<<" -> ";
            for(auto &val : nums)
            {
                cnt += (val>>i)&1;
                cnt %= 3;
            }
            // cout<<cnt<<" ";
            cnt %= 3;
            str += to_string(cnt);
        }
        
        int p = 31;
        
        int ans = 0;
        
        for(auto &ch : str)
        {
            int bit = ch - '0';
            if(bit)
                ans += (1<<p);
            --p;
        }
        
        return ans;
    }
};