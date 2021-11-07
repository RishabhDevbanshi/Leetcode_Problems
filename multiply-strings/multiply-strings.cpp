class Solution {
    string add(string &a,string &b)
    {
       int carry = 0;
        // cout<<a<<" "<<b<<"\n";
        int i=a.size()-1,j=b.size()-1;
        string ans = "";
        while(i>=0 && j>=0)
        {
            int res = (a[i] - '0') + (b[j]-'0') + carry;
            carry = res/10;
            int rem = res%10;
            ans += ('0' + rem);
            i-- , j--;
        }
        
        while(i>=0)
        {
            int res = (a[i] - '0') + carry;
            carry = res/10;
            int rem = res%10;
            ans += ('0' + rem);
            i--;
        }
        
        while(j>=0)
        {
            int res = (b[j]-'0') + carry;
            carry = res/10;
            int rem = res%10;
            ans += ('0' + rem);
            j--;
        }
        
        if(carry) ans += ('0' + carry);
        
        reverse(ans.begin(),ans.end());
        // cout<<ans<<"\n";
        return ans;
    }
    
    string mul(char &a,string &b,int idx)
    {
        string ans = "";
        int val = (a - '0');
        int carry = 0;
        
        for(int i=b.size()-1;i>=0;i--)
        {
            char ch = b[i];
            int oth = (ch - '0');
            int res = (val*oth) + carry;
            carry = res/10;
            int rem = res%10;
            ans += ('0' + rem);
        }
        if(carry) ans += (carry + '0');
        reverse(ans.begin(),ans.end());
        for(int i=0;i<idx;i++) ans += '0';
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        
        int idx = num1.size();
        --idx;
        
        string ans = "";
        
        for(auto &ch : num1)
        {
            string res = mul(ch,num2,idx--);
            ans = add(ans,res);
        }
        
        string res = "";
        int i=0;
        while(i<ans.size() && ans[i]=='0') i++;
        
        if(i == ans.size()) return "0";
        
        while(i<ans.size()) res += ans[i] , i++;
        
        return res;
    }
};