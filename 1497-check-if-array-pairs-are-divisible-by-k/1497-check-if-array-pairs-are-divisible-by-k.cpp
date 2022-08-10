class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k);
        for(auto &val : arr)
            freq[(val%k + k)%k]++;
        for(int i=0;i<k;i++)
        {
            if(i==0)
            {
                if(freq[i]&1)   return false;
            }
            else if(freq[i] != freq[k-i])
                return false;
        }
        
        return true;
    }
};