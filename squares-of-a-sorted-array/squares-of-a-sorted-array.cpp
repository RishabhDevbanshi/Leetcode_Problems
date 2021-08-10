class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> arr(n);
        int neg = -1, pos;
        for(int i=0;i<n;i++) 
        {
            if(A[i] < 0) neg = i;
        }

        pos = neg+1;
        int idx = 0;
        while(neg>=0 and pos<n)
        {
            if(abs(A[neg]) > A[pos])
            {
                arr[idx++] = A[pos] * A[pos];
                pos++;
            }
            else
            {
                arr[idx++] = A[neg] * A[neg];
                neg--;
            }
        }

        while(pos < n) {arr[idx++] = A[pos] * A[pos]; pos++;}
        while(neg >= 0) {arr[idx++] = A[neg] * A[neg]; neg--;}

        return arr;
    }
};