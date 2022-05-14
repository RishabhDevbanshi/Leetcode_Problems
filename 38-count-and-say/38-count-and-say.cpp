class Solution {
public:
    string countAndSay(int A) {
        if(A==1) return "1";
        if(A == 2) return "11";

        string str = "1";

        for(int x=1;x<A;x++)
        {
            string res = "";
            int cnt = 1;

            for(int i=1;i<str.size();i++)
            {
                if(str[i] == str[i-1]) {cnt++; continue;}
                else {
                    res += to_string(cnt) + str[i-1];
                    cnt = 1;
                }
            }

            res += to_string(cnt) + str[str.size()-1];
            str = res;
            // cout<<str<<" ";
        }
        // cout<<"\n";

        return str;
    }
};