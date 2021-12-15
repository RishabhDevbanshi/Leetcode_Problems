class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return 0;
        int obsp = -arr[0], ossp=0, ocsp=0;
        for(int i=1;i<n;i++)
        {
            int nbsp, ncsp, nssp;
            nbsp = (ocsp-arr[i])>obsp ? (ocsp-arr[i]) : obsp;
            nssp = (arr[i]+obsp) > ossp ? (arr[i]+obsp) : ossp;
            ncsp = max(ocsp,ossp);
            
            obsp = nbsp;
            ocsp = ncsp;
            ossp = nssp;
        }
        return ossp;
    }
};