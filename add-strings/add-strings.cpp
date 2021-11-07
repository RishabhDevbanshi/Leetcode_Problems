class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        int i=num1.size()-1 , j=num2.size()-1;
        while(i>=0 and j>=0)
        {
            int res = (num1[i] - '0') + (num2[j] - '0') + carry;
            carry = res/10;
            int rem = res%10;
            ans += ('0' + rem);
            i-- , j--;
        }
        while(i>=0)
        {
            int res = (num1[i] - '0') + carry;
            carry = res/10;
            int rem = res%10;
            ans += ('0' + rem);
            i--;
        }
        while(j>=0)
        {
            int res = (num2[j] - '0') + carry;
            carry = res/10;
            int rem = res%10;
            ans += ('0' + rem);
            j--;
        }
        
        if(carry) ans += (carry + '0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};