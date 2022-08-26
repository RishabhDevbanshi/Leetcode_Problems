class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        typedef pair<long double,pair<long double,long double>> pi;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        set<pair<long double,pair<long double,long double>>> st;
        for(int i=0;i<size(arr)-1;i++)
        {
            long double x = arr[i];
            pq.push({x/arr.back(),{arr[i],size(arr)-1}});
        }
        
        for(int j=0;j<k-1;j++)
        {
            auto beg = pq.top(); pq.pop();
            auto val = beg.first;
            auto num = beg.second.first , idx = beg.second.second;
            if(idx > 0)
            {
                idx--;
                if(arr[idx] == num) idx--;
                if(idx < 0) continue;
                long double x = num / arr[idx];
                pq.push({x,{num,idx}});
            }
        }
        
        auto it = pq.top();
        return {(int)it.second.first,(int)arr[it.second.second]};
    }
};