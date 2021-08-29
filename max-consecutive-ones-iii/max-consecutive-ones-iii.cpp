class Solution {
public:
    int longestOnes(vector<int>& A, int B) {
        int zeroes = 0;
        for(auto val : A) zeroes += val == 0;
        if(zeroes == 0 or zeroes <= B) return A.size();

        int bestWinSize = 0, zeroCount = 0;
        int left = 0 ,right = 0;
        while(right < A.size())
        {
            if(zeroCount <= B)
            {
                if(A[right] == 0) zeroCount++;
                right++;
            }

            if(zeroCount > B)
            {
                if(A[left] == 0) zeroCount--;
                left++;
            }

            if(right - left > bestWinSize and zeroCount <= B)
            {
                bestWinSize = right - left;
            }
        }

        return bestWinSize;
    }
};