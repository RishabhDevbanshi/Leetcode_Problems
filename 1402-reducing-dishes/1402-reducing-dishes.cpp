class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end(),greater<int>());
        
        int curr=0,tot=0;
        for(auto &sat : satisfaction)
        {
            curr += sat;
            if(curr < 0)
                break;
            tot += curr;
        }
        return tot;
    }
};