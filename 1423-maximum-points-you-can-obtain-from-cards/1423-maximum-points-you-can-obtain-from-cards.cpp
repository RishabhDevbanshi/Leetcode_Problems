class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int maxi = 0;
        
        for(int i=0;i<k;i++)
            sum += cardPoints[i];
        
        maxi = sum;
        int j = size(cardPoints)-1;
        
        int i = k-1;
        
        while(i >= 0)
        {
            sum += cardPoints[j--] - cardPoints[i--];
            maxi = max(maxi,sum);
        }
        
        return maxi;
    }
};