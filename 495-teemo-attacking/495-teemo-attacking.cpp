class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int tot = 0;
        for(int i=0;i<size(timeSeries);i++)
        {
            if(i == size(timeSeries)-1)
                tot += duration;
            else
                tot += min(duration , timeSeries[i+1] - timeSeries[i]);
        }
        
        return tot;
    }
};