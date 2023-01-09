class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot=0,curr=0,start=0;
        for(int i=0;i<size(gas);i++)
        {
            tot += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            if(curr<0)
                start = i+1,curr=0;
        }
        
        return tot < 0 ? -1 : start;
    }
};