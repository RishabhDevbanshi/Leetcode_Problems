class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n,0);
        if(k == 0)
        {
            return res;
        }
        else if(k<0)
        {
            int j=n-1;
            int i=n-1 , cnt = 1;
            while(cnt < abs(k) and i>=0) i-- , cnt++;
            int sum = 0;
            for(int x=i;x<=j;x++) sum += code[x];
            // cout<<i<<" "<<j;
            for(int x=0;x<n;x++)
            {
                res[x] = sum;
                sum -= code[i];
                i = (i+1)%n , j = (j+1)%n;
                sum += code[j];
            }
        }
        else
        {
            int j=1,i=1,cnt=1;
            while(cnt < k) i++ , cnt++;
            int sum = 0;
            for(int x=j;x<=i;x++) sum += code[x];
            // cout<<i<<" "<<j;
            for(int x=0;x<n;x++)
            {
                res[x] = sum;
                sum -= code[j];
                i = (i+1)%n , j = (j+1)%n;
                sum += code[i];
            }
        }
        
        return res;
    }
};