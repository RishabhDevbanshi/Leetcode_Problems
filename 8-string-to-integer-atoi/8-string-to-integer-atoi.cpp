class Solution {
public:
    int myAtoi(string s) {
        string num = "";
        
        int i=0;
        while(i<size(s) and s[i] == ' ') i++;
        
        bool isNeg = false;
        
        if(s[i] == '-') isNeg = true , i++;
        else if(s[i] == '+') i++;
        
        while(i<size(s))
        {
            if(s[i]>='0' and s[i]<='9') num += s[i];
            else break;
            
            i++;
        }
        
        // cout<<num<<" ";
        
        long long res = 0;
        
        bool ovf = false;
        
        i=0;
        
        // cout<<num<<"\n";
        
        long long mn = INT_MIN;
        mn = abs(mn);
        
        while(i<size(num))
        {
            res = (res*10) + (num[i] - '0');
            
            // cout<<res<<"\n";
            
            if(isNeg and res > mn) return INT_MIN;
            else if(!isNeg and res > INT_MAX) return INT_MAX;
            
            i++;
        }
        
        if(isNeg) res = -res;
        
        return res;
        
    }
};













