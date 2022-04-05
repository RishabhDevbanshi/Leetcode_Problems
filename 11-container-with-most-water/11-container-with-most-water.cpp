class Solution {
public:
    int maxArea(vector<int>& A) {
        int start = 0 , end = A.size() - 1 , ans = 0;
        while(start < end)
        {
            int w = end - start;
            int l = min(A[start],A[end]);
            int area = l * w;
            ans = max(ans,area);
            if(A[start] <  A[end]) start++;
            else end--;
        }

        return ans;
    }
};