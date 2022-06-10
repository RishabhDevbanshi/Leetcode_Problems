class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int cnt = 0;
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%3 != 0)
            return false;
        
        int tot = 0;
        for(int i=0;i<size(arr);i++)
        {
            tot += arr[i];
            if(tot == sum/3)
                cnt++ , tot = 0;
        }
        
        return cnt >= 3;
    }
};