class Solution {
public:
    string largestNumber(vector<int>& A) {
        int n = A.size();
        vector<string> arr(n);
        int cnt = 0;
        for(int i=0;i<n;i++) 
        {
            cnt += (A[i] == 0);
            arr[i] = to_string(A[i]);
        }

        if(cnt == n) return "0";

        sort(arr.begin(),arr.end(),[](string a,string b){
            return a+b > b+a;
        });

        string ans = "";
        for(auto ch : arr) ans += ch;

        return ans;
    }
};