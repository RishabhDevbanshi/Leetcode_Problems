class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = INT_MIN;
        int n = candies.size();
        for(auto ele : candies) mx = max(mx,ele);
        
        vector<bool> ans(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(candies[i] + extraCandies >= mx) ans[i] = true;
        }
        
        return ans;
    }
};