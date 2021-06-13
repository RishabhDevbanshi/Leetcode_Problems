class Solution {
    int cnt;
    void util(vector<vector<int>> &arr,int idx,int maxLen)
    {
        if(idx == arr.size()) return ;
        
        int l = arr[idx][0] , w = arr[idx][1];
        int mn = min(l,w);
        // cout<<l<<" "<<w<<" "<<mn<<" "<<maxLen<<"\n";
        if(mn > maxLen) {maxLen = mn, cnt = 1;}
        else if(mn == maxLen) cnt++;
        
        util(arr,idx+1,maxLen);
    }
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        cnt = 0;
        util(rectangles,0,INT_MIN);
        
        return cnt;
    }
};