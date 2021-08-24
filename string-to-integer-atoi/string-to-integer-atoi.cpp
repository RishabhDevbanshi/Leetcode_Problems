class Solution {
public:
    int myAtoi(string A) {
        int n = A.size();
        int i=0;
        while(i<n)
        {
            if(A[i] == ' ') i++;
            else break;
        }
        bool neg = false;
        if(A[i] == '-') neg=true,i++;
        else if(A[i] == '+') i++;

        int num = 0;
        string str = "";
        
        while(i<n)
        {
            if(A[i] != '0') break;
            else i++;
        }
        
        while(i<n)
        {
            if(A[i] <= '9' and A[i] >= '0')
            {
                str += A[i];
            }
            else break;
            i++;
        }

        long long res = 0;
        bool ovf = false;
        int p = 0;
        for(int i=str.size()-1;i>=0;i--)
        {
            int val = str[i] - '0';
            res += val * pow(10,p);
            p++;
            if((p>10) or res > INT_MAX) {ovf=true; break;}
        }

        if(ovf)
        {
            if(neg) return INT_MIN;
            else return INT_MAX;
        }

        if(neg) return -res;
        else return res;
    }
};