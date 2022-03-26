class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        
        int ans = 0;
        for(int i=1;i<=size(citations);i++)
        {
            if(citations[i-1] < i)
                break;
            ans = i;
        }
        
        return ans;
    }
};