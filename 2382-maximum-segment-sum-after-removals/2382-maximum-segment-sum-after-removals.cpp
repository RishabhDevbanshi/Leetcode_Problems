class Solution {
public:
 vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& queries) {
    
    long long mxsum = 0;
    vector<long long> res{0};
    map<pair<int,int>,long long> mp;

    for(int i=queries.size()-1;i>0;i--){

        int idx = queries[i];
        auto it = mp.lower_bound({idx,idx});

        // try merging right
        if( it != mp.end() ){
            int l = it->first.first, r = it->first.second;
            long long sum = it->second;

            if( abs(idx - l) == 1){
                mp.erase(it);
                mp[{idx,r}] = sum+nums[idx];
                mxsum = max( mxsum, sum+nums[idx]);
            }
            else{
                mp[{idx,idx}] = nums[idx];
                mxsum = max(mxsum, nums[idx]*1LL);
            }

        }
        else{
            mp[{idx,idx}] = nums[idx];
            mxsum = max(mxsum, nums[idx]*1LL);
        }

        // try merging left
        it = mp.lower_bound({idx,0});
        if( it != mp.begin() ){
            
            auto it2 = prev(it);
            int l1 = it2->first.first, r1 = it2->first.second;
            long long sum1 = it2->second;

            int l2 = it->first.first, r2 = it->first.second;
            long long sum2 = it->second;

            if( abs(r1 - l2) == 1){
                mp.erase(it);
                mp.erase(it2);
                mp[{l1,r2}] = sum1+sum2;
                mxsum = max(mxsum , sum1+sum2);
            }
        }
        res.push_back(mxsum);
    }
    reverse(res.begin(), res.end());
    return res;
}};