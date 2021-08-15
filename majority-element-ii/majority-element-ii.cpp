class Solution {
    bool check(vector<int> &arr,int can)
    {
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n;i++) cnt += arr[i] == can;

        return cnt > n/3;
    }

public:
    vector<int> majorityElement(vector<int>& A) {
        int val1= INT_MIN , val2= INT_MIN, cnt1=0, cnt2=0;
        int n = A.size();

        for(int i=0;i<n;i++)
        {
            if(A[i] == val1) cnt1++;
            else if(A[i] == val2) cnt2++;
            else if(cnt1 == 0)
            {
                val1 = A[i]; cnt1++;
            }
            else if(cnt2 == 0)
            {
                val2 = A[i]; cnt2++;
            }
            else 
            {
                cnt1--; cnt2--;
            }
        }
        
        vector<int> res;
        
        if(check(A,val1)) res.push_back(val1);
        if(check(A,val2)) res.push_back(val2);
        
        return res;
    }
};