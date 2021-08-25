class Solution {
public:
    string intToRoman(int A) {
        vector<char> arr;
        while(A)
        {
            char ch = (A%10) + '0';
            arr.push_back(ch);
            A/=10;
        }
        reverse(arr.begin(),arr.end());
        int n = arr.size();
        string str = "";
        for(int i=0;i<n;i++)
        {
            int p = n - i - 1;
            int val = arr[i] - '0';
            if(p == 3)
            {
                for(int i=0;i<val;i++) str += 'M';
            }
            else if(p == 2)
            {
                if(val == 9) str += "CM";
                else if(val >= 5) 
                {
                    str += 'D'; val -= 5;
                    for(int i=0;i<val;i++) str += 'C';
                }
                else if(val == 4) str += "CD";
                else for(int i=0;i<val;i++) str += 'C';
            }
            else if(p == 1)
            {
                if(val == 9) str += "XC";
                else if(val >= 5) 
                {
                    str += 'L'; val -= 5;
                    for(int i=0;i<val;i++) str += 'X';
                }
                else if(val == 4) str += "XL";
                else for(int i=0;i<val;i++) str += 'X';
            }
            else 
            {
                if(val == 9) str += "IX";
                else if(val >= 5) 
                {
                    str += 'V'; val -= 5;
                    for(int i=0;i<val;i++) str += 'I';
                }
                else if(val == 4) str += "IV";
                else for(int i=0;i<val;i++) str += 'I';
            }
        }


        return str;
    }
};